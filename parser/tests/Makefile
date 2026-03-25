NAME = syntax_tests
NAME_SUBST = substitution_tests
CC = cc

SRCS = \
	syntax_tests.c \
	../tokenizer.c \
	../linked_list_ops.c \
	../string_utils.c \
	../syntax_check.c \
	../tokenizer_utils.c

SRCS_SUBST = \
	substitution_tests.c \
	../tokenizer.c \
	../linked_list_ops.c \
	../string_utils.c \
	../syntax_check.c \
	../tokenizer_utils.c \
	../substitutions.c

OBJC = $(SRCS:.c=.o)
OBJC_SUBST = $(SRCS_SUBST:.c=.o)

%.o: %.c syntax_tests.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(OBJC) -o $(NAME)

$(NAME_SUBST): $(OBJC_SUBST)
	$(CC) $(OBJC_SUBST) -o $(NAME_SUBST)

run: all
	./$(NAME)

run_subst: $(NAME_SUBST)
	./$(NAME_SUBST)

fclean:
	rm -f $(OBJC) $(OBJC_SUBST) $(NAME) $(NAME_SUBST)

.PHONY: fclean all run run_subst