# libft-tester

A portable, crash-safe tester for the 42 Libft project.

This tester was built against the provided **Libft subject v19.3**. In that
subject, the libc functions, additional functions, and linked-list functions are
all mandatory. There is no separate bonus chapter in this subject version, so
`--bonus` is accepted but has no configured bonus-only tests.

## Usage

```sh
make
./libft-tester ../libft
./libft-tester ../libft --mandatory
./libft-tester ../libft --all
./libft-tester ../libft --leaks
./libft-tester ../libft --asan
./libft-tester ../libft --verbose
./libft-tester ../libft --only ft_memmove
./libft-tester ../libft --source-build
./libft-tester ../libft --source-build --only ft_memmove
./libft-tester ../libft --json report.json
./libft-tester --update
```

`--source-build` is for early/incomplete projects. It skips the submitted
Makefile, compiles the available `.c` files directly into a temporary
`libft.a`, and creates a temporary compatibility `libft.h` when the project has
no header yet. With `--only`, it compiles only the matching function source file
so a single function can be tested before the whole project builds.

## Memory Checks

Recommended commands:

```sh
# Linux, when Valgrind is installed
libft-tester . --valgrind

# macOS
libft-tester . --asan

# Smart mode: Valgrind when available, otherwise ASan
libft-tester . --leaks
```

Notes:

- `--leaks` is the safest default for mixed environments.
- On Linux, `--valgrind` gives the strictest leak report when Valgrind is installed.
- On macOS, Valgrind is usually unavailable or unreliable. Use `--asan`.
- If `--valgrind` is used on macOS and Valgrind is not found, the tester falls
  back to ASan/UBSan and prints a warning.
- Apple's ASan does not provide strict LeakSanitizer support in this setup, so
  macOS ASan is best for invalid reads/writes and undefined behavior diagnostics,
  not strict leak grading.

## Install

The recommended install keeps the repository in your home directory and creates
a `libft-tester` command in `~/.local/bin`. Both paths are inside your home
directory, so this works well on shared 42 computers and does not require
installing the tester into a system directory.

### 42 Campus / Shared Computer

Use this when `git`, `make`, and `cc` are already available:

```sh
cd ~
git clone https://github.com/tamerakdeniz/libft-tester.git
cd ~/libft-tester
make install
grep -qxF 'export PATH="$HOME/.local/bin:$PATH"' ~/.zshrc || echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.zshrc
export PATH="$HOME/.local/bin:$PATH"
libft-tester --help
```

If your campus shell is Bash, replace `~/.zshrc` with `~/.bashrc`.

### Linux

Copy-paste this in a terminal:

```sh
sudo apt update
sudo apt install -y git build-essential
cd ~
git clone https://github.com/tamerakdeniz/libft-tester.git
cd ~/libft-tester
make install
grep -qxF 'export PATH="$HOME/.local/bin:$PATH"' ~/.bashrc || echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
export PATH="$HOME/.local/bin:$PATH"
libft-tester --help
```

### macOS

Copy-paste this in Terminal:

```sh
xcode-select --install 2>/dev/null || true
cd ~
git clone https://github.com/tamerakdeniz/libft-tester.git
cd ~/libft-tester
make install
grep -qxF 'export PATH="$HOME/.local/bin:$PATH"' ~/.zshrc || echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.zshrc
export PATH="$HOME/.local/bin:$PATH"
libft-tester --help
```

If you use Bash on macOS, replace `~/.zshrc` with `~/.bashrc`.

### Windows

Native Windows CMD/PowerShell is not supported. Use WSL with Ubuntu.

First, run this in PowerShell:

```powershell
wsl --install -d Ubuntu
```

Restart if Windows asks you to, then open Ubuntu and run:

```sh
sudo apt update
sudo apt install -y git build-essential
cd ~
git clone https://github.com/tamerakdeniz/libft-tester.git
cd ~/libft-tester
make install
grep -qxF 'export PATH="$HOME/.local/bin:$PATH"' ~/.bashrc || echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
export PATH="$HOME/.local/bin:$PATH"
libft-tester --help
```

### Run From Any Libft Project

After install:

```sh
cd /path/to/your/libft
libft-tester . --all
libft-tester . --only ft_memset
libft-tester . --asan
```

### Update Or Uninstall

Update:

```sh
libft-tester --update
```

Uninstall:

```sh
cd ~/libft-tester
make uninstall
```

## Updates

When run in an interactive terminal from a git checkout, `libft-tester` checks
the GitHub remote briefly. If a newer remote `HEAD` is available, it prints a
warning and keeps running the requested tests.

Update the tester with:

```sh
libft-tester --update
```

The update command runs `git pull --ff-only` in the tester checkout. It refuses
to run when the tester checkout has local changes.

Disable the automatic update check for one run:

```sh
libft-tester . --no-update-check
```

Or disable it through the environment:

```sh
LIBFT_TESTER_NO_UPDATE_CHECK=1 libft-tester .
```

## Output

The default output is grouped by phase and keeps result columns aligned:

```text
libft-tester
Project : /path/to/libft
Subject : Libft v19.3
Mode    : mandatory
Only    : ft_memset
Timeout : 3s
Memory  : off

Build
-----
Compiling a temporary copy of the submitted project.

Functional Tests
----------------
Count: 1
[001/001] PASS    ft_memset.cases                        7 ms  return value, signed/wide byte conversion, len 0

Summary
-------
Passed     1
Failed     0
Warnings   0
Skipped    0
```

## What it does

- Copies the submitted Libft project into a temporary directory before building.
- Runs `make all` in the copy, so the original project directory is not modified.
- With `--source-build`, skips `make` and builds `libft.a` directly from
  available `.c` files, with a temporary compatibility `libft.h` if needed.
- Finds and links the produced `libft.a`.
- Runs each test as a separate process with a timeout.
- Reports crashes by signal name, including `SIGSEGV`, `SIGABRT`, `SIGBUS`, and
  `SIGFPE`.
- Supports optional memory passes with `--valgrind`, `--asan`, or `--leaks`.
  ASan uses a separately copied build with sanitizer `CFLAGS` when the submitted
  Makefile honors command-line variables.
- Writes CI-friendly exit codes: `0` for success, `1` for required test failures,
  and `2` for tester/build setup errors.
- Can keep temporary build files with `--keep-tmp`.
- Warns about newer tester versions during interactive terminal use and supports
  self-updating with `libft-tester --update`.

The tester includes strict subject tests and non-strict probe tests. Probe tests
exercise undefined-behavior-adjacent inputs such as selected `NULL` arguments;
probe warnings are useful diagnostics but do not affect the exit code.
