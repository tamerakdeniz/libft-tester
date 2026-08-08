NAME := libft-tester

.PHONY: all test clean fclean re

all:
	@chmod +x $(NAME)
	@printf 'Ready: ./$(NAME) <path-to-libft>\n'

test:
	@python3 -c "from pathlib import Path; compile(Path('$(NAME)').read_text(), '$(NAME)', 'exec')"
	@cc -Wall -Wextra -Werror -g -O0 -DLT_DISABLE_ALLOC_WRAP=1 src/libft_test_harness.c -o /tmp/libft_harness_syntax
	@rm -f /tmp/libft_harness_syntax

clean:
	@rm -rf .pytest_cache __pycache__ src/__pycache__

fclean: clean

re: fclean all
