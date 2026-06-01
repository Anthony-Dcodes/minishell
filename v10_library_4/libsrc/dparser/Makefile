# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: advorace <advorace@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 09:22:10 by omayer            #+#    #+#              #
#    Updated: 2026/06/01 18:48:06 by advorace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../../lib/l_dparser.a
CC := clang

SRCH := convert_to_tlistx.h \
		macros.h \
		parser_advorace.h \
		pr_dparser.h \
		remove_quotes.h \
		string_utils.h \
		structs.h \
		substitution.h \
		syntax_checker.h \
		tokenizer.h

SRCL := pr_dparser.c \
		pr_dparser_a.c \
		pr_dparser_b.c \
		pr_dparser_c.c \
		convert_to_tlistx.c \
		convert_to_tlistx_helpers.c \
		remove_quotes.c \
		string_utils2.c \
		string_utils.c \
		substitution_copy_job.c \
		substitutions.c \
		substitution_utils.c \
		substitution_valid_env_chars.c \
		syntax_checker.c \
		tokenizer.c \
		tokenizer_char_utils.c \
		tokenizer_meta_data.c \
		tokenizer_meta_data_utils.c \
		tokenizer_string_utils.c \
		tokenizer_token_utils.c

OBJL := $(patsubst %.c, %.o, $(SRCL))

%: %.c
	$(CC) -Wall -Wextra -Werror $(SRCH) -c $(SRCL)

all: $(NAME)

$(NAME): $(OBJL)
	ar rsc $(NAME) $(OBJL)

clean:
	rm -f $(OBJL)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
