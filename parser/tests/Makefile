NAME = syntax_tests
NAME_SUBST = substitution_tests
NAME_TOKENIZER = tokenizer_tests
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

SRCS_TOKENIZER = \
	tokenizer_tests.c \
	../tokenizer.c \
	../linked_list_ops.c \
	../string_utils.c \
	../syntax_check.c \
	../tokenizer_utils.c \
	../substitutions.c

OBJC = $(SRCS:.c=.o)
OBJC_SUBST = $(SRCS_SUBST:.c=.o)
OBJC_TOKENIZER = $(SRCS_TOKENIZER:.c=.o)

%.o: %.c syntax_tests.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(NAME_SUBST) $(NAME_TOKENIZER)

$(NAME): $(OBJC)
	$(CC) $(OBJC) -o $(NAME)

$(NAME_SUBST): $(OBJC_SUBST)
	$(CC) $(OBJC_SUBST) -o $(NAME_SUBST)

$(NAME_TOKENIZER): $(OBJC_TOKENIZER)
	$(CC) $(OBJC_TOKENIZER) -o $(NAME_TOKENIZER)

run: all
	./$(NAME)

run_subst: $(NAME_SUBST)
	./$(NAME_SUBST)

run_tokenizer: $(NAME_TOKENIZER)
	./$(NAME_TOKENIZER)

fclean:
	rm -f $(OBJC) $(OBJC_SUBST) $(NAME) $(NAME_SUBST) $(NAME_TOKENIZER)

re: fclean all

.PHONY: fclean all run run_subst run_tokenizer re