NAME = parser
CC = cc
CFLAGS = -Wall -Wextra #-Werror

SRCS = \
	parser.c \
	remove_quotes.c \
	string_utils.c \
	substitution_utils.c \
	substitution_valid_env_chars.c \
	substitutions.c \
	syntax_checker.c \
	tokenizer_char_utils.c \
	tokenizer_string_utils.c \
	tokenizer_token_utils.c \
	tokenizer.c

OBJC = $(SRCS:.c=.o)

# --- Rebuild if headers change ---
%.o: %.c parser.h
	$(CC) $(CFLAGS) -c $< -o $@

# --- Build rules ---

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(CC_FLAGS) $(OBJC) -o $(NAME)

run: all
	./$(NAME); echo "exit status: $$?"

test: all
	./tester.sh

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run test
