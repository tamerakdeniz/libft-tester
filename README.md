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
./libft-tester ../libft --json report.json
```

## Install globally

Install a symlink into `~/.local/bin`:

```sh
make install
```

If `~/.local/bin` is not already in your shell `PATH`, add this line to your
shell config (`~/.zshrc`, `~/.bashrc`, or equivalent):

```sh
export PATH="$HOME/.local/bin:$PATH"
```

After that, run the tester from any Libft project directory:

```sh
cd ../libft
libft-tester . --all
libft-tester . --only ft_memset
```

To install somewhere else:

```sh
make install PREFIX=/usr/local
```

To remove the symlink:

```sh
make uninstall
```

## What it does

- Copies the submitted Libft project into a temporary directory before building.
- Runs `make all` in the copy, so the original project directory is not modified.
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

The tester includes strict subject tests and non-strict probe tests. Probe tests
exercise undefined-behavior-adjacent inputs such as selected `NULL` arguments;
probe warnings are useful diagnostics but do not affect the exit code.
