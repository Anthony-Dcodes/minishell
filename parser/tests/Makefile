NAME = syntax_tests
CC = cc

SRCS = \
	syntax_tests.c \
	../lexer.c \
	../linked_list_ops.c \
	../string_helpers.c \
	../string_utils.c \
	../syntax_check.c \
	../tokenizer_utils.c

OBJC = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(OBJC) -o $(NAME)

run: all
	./$(NAME)

fclean:
	rm -f $(OBJC) $(NAME)

.PHONY: fclean all
