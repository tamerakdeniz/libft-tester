NAME := libft-tester
PREFIX ?= $(HOME)/.local
BINDIR ?= $(PREFIX)/bin

.PHONY: all install uninstall test clean fclean re

all:
	@chmod +x $(NAME)
	@printf 'Ready: ./$(NAME) <path-to-libft>\n'

install: all
	@mkdir -p "$(BINDIR)"
	@if [ -e "$(BINDIR)/$(NAME)" ] && [ ! -L "$(BINDIR)/$(NAME)" ]; then printf 'Refusing to overwrite non-symlink: $(BINDIR)/$(NAME)\n'; exit 1; fi
	@ln -sf "$(CURDIR)/$(NAME)" "$(BINDIR)/$(NAME)"
	@printf 'Installed: $(BINDIR)/$(NAME) -> $(CURDIR)/$(NAME)\n'
	@case ":$$PATH:" in *":$(BINDIR):"*) ;; *) printf 'Add this to your shell config if needed: export PATH="$(BINDIR):$$PATH"\n';; esac

uninstall:
	@if [ -L "$(BINDIR)/$(NAME)" ]; then rm "$(BINDIR)/$(NAME)"; printf 'Removed: $(BINDIR)/$(NAME)\n'; else printf 'No symlink found at $(BINDIR)/$(NAME)\n'; fi

test:
	@python3 -c "from pathlib import Path; compile(Path('$(NAME)').read_text(), '$(NAME)', 'exec')"
	@cc -Wall -Wextra -Werror -g -O0 -DLT_DISABLE_ALLOC_WRAP=1 src/libft_test_harness.c -o /tmp/libft_harness_syntax
	@rm -f /tmp/libft_harness_syntax

clean:
	@rm -rf .pytest_cache __pycache__ src/__pycache__

fclean: clean

re: fclean all
