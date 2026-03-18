NAME = parser
CC = cc
CFLAGS = -Wall -Wextra #-Werror

SRCS = \
	lexer.c \
	linked_list_ops.c \
	parser.c \
	string_helpers.c

OBJC = $(SRCS:.c=.o)

# --- Rebuild if headers change ---
%.o: %.c parser.h
	$(CC) $(CFLAGS) -c $< -o $@

# --- Build rules ---

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(CC_FLAGS) $(OBJC) -o $(NAME)

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
