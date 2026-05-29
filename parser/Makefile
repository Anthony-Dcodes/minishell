NAME = parser
ARCH = parser_advorace.a
ARCH_H = parser_advorace.h
INTEGRATE_DEST = ../omayer_lib/v10_library/libsrc/dparser/
CC = cc
CFLAGS = -Wall -Wextra #-Werror

SRCS = \
	convert_to_tlistx.c \
	convert_to_tlistx_helpers.c \
	parser.c \
	remove_quotes.c \
	string_utils.c \
	string_utils2.c \
	substitution_copy_job.c \
	substitution_utils.c \
	substitution_valid_env_chars.c \
	substitutions.c \
	syntax_checker.c \
	tokenizer.c \
	tokenizer_char_utils.c \
	tokenizer_meta_data.c \
	tokenizer_meta_data_utils.c \
	tokenizer_string_utils.c \
	tokenizer_token_utils.c

HEADERS = \
	convert_to_tlistx.h \
	macros.h \
	parser.h \
	remove_quotes.h \
	string_utils.h \
	structs.h \
	substitution.h \
	syntax_checker.h \
	tokenizer.h \

OBJC = $(SRCS:.c=.o)

# --- Rebuild if headers change ---
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Build rules ---

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(CC_FLAGS) $(OBJC) -o $(NAME)

arch: $(OBJC)
	ar rcs $(ARCH) $(OBJC)

integrate: arch integrate_rm integrate_cp
	$(MAKE) -C $(INTEGRATE_DEST) re

integrate_rm:
	rm -f $(addprefix $(INTEGRATE_DEST), $(ARCH) $(ARCH_H) $(HEADERS))

integrate_cp:
	cp $(ARCH) $(ARCH_H) $(HEADERS) $(INTEGRATE_DEST)


run: all
	./$(NAME); echo "exit status: $$?"

test: all
	./tester.sh

clean:
	rm -f $(OBJC)
	rm -f $(ARCH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run test
