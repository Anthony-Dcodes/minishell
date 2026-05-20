NAME_TOKENIZER = tokenizer_tests
NAME_SYNTAX = syntax_tests
NAME_SUBST = substitution_tests
CC = cc

SRCS_TOKENIZER = \
	tokenizer_tests.c \
	../tokenizer.c \
	../tokenizer_char_utils.c \
	../tokenizer_string_utils.c \
	../tokenizer_token_utils.c \
	../string_utils.c \
	../syntax_check.c \
	../substitutions.c

SRCS_SYNTAX = \
	syntax_tests.c \
	../tokenizer.c \
	../tokenizer_char_utils.c \
	../tokenizer_string_utils.c \
	../tokenizer_token_utils.c \
	../string_utils.c \
	../syntax_check.c \
	../substitutions.c

SRCS_SUBST = \
	substitution_tests.c \
	../tokenizer.c \
	../tokenizer_char_utils.c \
	../tokenizer_string_utils.c \
	../tokenizer_token_utils.c \
	../string_utils.c \
	../syntax_check.c \
	../substitutions.c


OBJC_TOKENIZER = $(SRCS_TOKENIZER:.c=.o)
OBJC_SYNTAX = $(SRCS_SYNTAX:.c=.o)
OBJC_SUBST = $(SRCS_SUBST:.c=.o)

%.o: %.c tokenizer_tests.h syntax_tests.h substitution_tests.h macros.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_TOKENIZER) $(NAME_SYNTAX) $(NAME_SUBST)

$(NAME_TOKENIZER): $(OBJC_TOKENIZER)
	$(CC) $(OBJC_TOKENIZER) -o $(NAME_TOKENIZER)

$(NAME_SYNTAX): $(OBJC_SYNTAX)
	$(CC) $(OBJC_SYNTAX) -o $(NAME_SYNTAX)

$(NAME_SUBST): $(OBJC_SUBST)
	$(CC) $(OBJC_SUBST) -o $(NAME_SUBST)

run_tokenizer: $(NAME_TOKENIZER)
	./$(NAME_TOKENIZER)

run_syntax: all
	./$(NAME_SYNTAX)

run_subst: $(NAME_SUBST)
	./$(NAME_SUBST)

run_all: all
	./$(NAME_TOKENIZER)
	./$(NAME_SYNTAX)
	./$(NAME_SUBST)

fclean:
	rm -f $(NAME_TOKENIZER) $(NAME_SYNTAX) $(NAME_SUBST) $(OBJC_TOKENIZER) $(OBJC_SYNTAX) $(OBJC_SUBST)

re: fclean all

.PHONY: fclean all run_syntax run_subst run_tokenizer re run_all
