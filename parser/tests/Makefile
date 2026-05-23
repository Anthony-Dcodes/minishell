NAME_TOKENIZER = tokenizer_tests
NAME_SYNTAX = syntax_tests
NAME_SUBST = substitution_tests
NAME_QUOTES = remove_quotes_tests
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS_COMMON = \
	../tokenizer.c \
	../tokenizer_char_utils.c \
	../tokenizer_string_utils.c \
	../tokenizer_token_utils.c \
	../string_utils.c \
	../syntax_checker.c \
	../substitutions.c \
	../substitution_utils.c \
	../substitution_valid_env_chars.c \
	../remove_quotes.c \
	../remove_quotes_skip_idx_list.c

SRCS_TOKENIZER = \
	tokenizer_tests.c

SRCS_SYNTAX = \
	syntax_tests.c

SRCS_SUBST = \
	substitution_tests.c

SRCS_QUOTES = \
	remove_quotes_tests.c

OBJC_TOKENIZER = $(SRCS_COMMON:.c=.o) $(SRCS_TOKENIZER:.c=.o)
OBJC_SYNTAX = $(SRCS_COMMON:.c=.o) $(SRCS_SYNTAX:.c=.o)
OBJC_SUBST = $(SRCS_COMMON:.c=.o) $(SRCS_SUBST:.c=.o)
OBJC_QUOTES = $(SRCS_COMMON:.c=.o) $(SRCS_QUOTES:.c=.o)

%.o: %.c tokenizer_tests.h syntax_tests.h substitution_tests.h macros.h remove_quotes_tests.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_TOKENIZER) $(NAME_SYNTAX) $(NAME_SUBST) $(NAME_QUOTES)

$(NAME_TOKENIZER): $(OBJC_TOKENIZER)
	$(CC) $(OBJC_TOKENIZER) -o $(NAME_TOKENIZER)

$(NAME_SYNTAX): $(OBJC_SYNTAX)
	$(CC) $(OBJC_SYNTAX) -o $(NAME_SYNTAX)

$(NAME_SUBST): $(OBJC_SUBST)
	$(CC) $(OBJC_SUBST) -o $(NAME_SUBST)

$(NAME_QUOTES): $(OBJC_QUOTES)
	$(CC) $(OBJC_QUOTES) -o $(NAME_QUOTES)

run_tokenizer: $(NAME_TOKENIZER)
	./$(NAME_TOKENIZER)

run_syntax: $(NAME_SYNTAX)
	./$(NAME_SYNTAX)

run_subst: $(NAME_SUBST)
	./$(NAME_SUBST)

run_quotes: $(NAME_QUOTES)
	./$(NAME_QUOTES)

run_all: all
	./$(NAME_TOKENIZER)
	./$(NAME_SYNTAX)
	./$(NAME_SUBST)
	./$(NAME_QUOTES)

fclean:
	rm -f \
		$(NAME_TOKENIZER) \
		$(NAME_SYNTAX) \
		$(NAME_SUBST) \
		$(NAME_QUOTES) \
		$(OBJC_TOKENIZER) \
		$(OBJC_SYNTAX) \
		$(OBJC_SUBST) \
		$(OBJC_QUOTES)

re: fclean all

.PHONY: \
	fclean \
	all \
	run_syntax \
	run_subst \
	run_tokenizer \
	re \
	run_all \
	run_quotes
