NAME_TOKENIZER = tokenizer_tests
NAME_SYNTAX = syntax_tests
NAME_SUBST = substitution_tests
NAME_QUOTES = remove_quotes_tests
NAME_SKIPPING = quote_skipping
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
	../tokenizer_meta_data.c \
	../tokenizer_meta_data_utils.c \
	../substitution_copy_job.c \
	../convert_to_tlistx_helpers.c \
	../convert_to_tlistx.c

SRCS_TOKENIZER = \
	tokenizer_tests.c

SRCS_SYNTAX = \
	syntax_tests.c

SRCS_SUBST = \
	substitution_tests.c

SRCS_QUOTES = \
	remove_quotes_tests.c

SRCS_SKIPPING = \
	quote_skipping.c

OBJC_TOKENIZER = $(SRCS_COMMON:.c=.o) $(SRCS_TOKENIZER:.c=.o)
OBJC_SYNTAX = $(SRCS_COMMON:.c=.o) $(SRCS_SYNTAX:.c=.o)
OBJC_SUBST = $(SRCS_COMMON:.c=.o) $(SRCS_SUBST:.c=.o)
OBJC_QUOTES = $(SRCS_COMMON:.c=.o) $(SRCS_QUOTES:.c=.o)
OBJC_SKIPPING = $(SRCS_COMMON:.c=.o) $(SRCS_SKIPPING:.c=.o)

%.o: %.c tokenizer_tests.h syntax_tests.h substitution_tests.h macros.h remove_quotes_tests.h quote_skipping.h convert_to_tlistx.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_TOKENIZER) $(NAME_SYNTAX) $(NAME_SUBST) $(NAME_QUOTES) $(NAME_SKIPPING)

$(NAME_TOKENIZER): $(OBJC_TOKENIZER)
	$(CC) $(OBJC_TOKENIZER) -o $(NAME_TOKENIZER)

$(NAME_SYNTAX): $(OBJC_SYNTAX)
	$(CC) $(OBJC_SYNTAX) -o $(NAME_SYNTAX)

$(NAME_SUBST): $(OBJC_SUBST)
	$(CC) $(OBJC_SUBST) -o $(NAME_SUBST)

$(NAME_QUOTES): $(OBJC_QUOTES)
	$(CC) $(OBJC_QUOTES) -o $(NAME_QUOTES)

$(NAME_SKIPPING): $(OBJC_SKIPPING)
	$(CC) $(OBJC_SKIPPING) -o $(NAME_SKIPPING)

run_tokenizer: $(NAME_TOKENIZER)
	./$(NAME_TOKENIZER)

run_syntax: $(NAME_SYNTAX)
	./$(NAME_SYNTAX)

run_subst: $(NAME_SUBST)
	./$(NAME_SUBST)

run_quotes: $(NAME_QUOTES)
	./$(NAME_QUOTES)

run_skipping: $(NAME_SKIPPING)
	./$(NAME_SKIPPING)

run_all: all
	./$(NAME_TOKENIZER)
	./$(NAME_SYNTAX)
	./$(NAME_QUOTES)
	./$(NAME_SKIPPING)
	./$(NAME_SUBST)

fclean:
	rm -f \
		$(NAME_TOKENIZER) \
		$(NAME_SYNTAX) \
		$(NAME_SUBST) \
		$(NAME_QUOTES) \
		$(NAME_SKIPPING) \
		$(OBJC_TOKENIZER) \
		$(OBJC_SYNTAX) \
		$(OBJC_SUBST) \
		$(OBJC_QUOTES) \
		$(OBJC_SKIPPING)

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
