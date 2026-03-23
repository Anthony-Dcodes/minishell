NAME = parser
CC = cc
CFLAGS = -Wall -Wextra #-Werror

SRCS = \
	tokenizer.c \
	linked_list_ops.c \
	parser.c \
	string_utils.c \
	syntax_check.c \
	tokenizer_utils.c \
	substitutions.c

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
