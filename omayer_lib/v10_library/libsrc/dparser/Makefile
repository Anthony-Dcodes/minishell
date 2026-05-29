# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: advorace <advorace@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 09:22:10 by omayer            #+#    #+#              #
#    Updated: 2026/05/29 09:53:39 by advorace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../../lib/l_dparser.a
CC := clang
SRCL := pr_dparser_a.c \
		pr_dparser_b.c \
		pr_dparser_c.c \
		pr_dparser.c

OBJL := $(patsubst %.c, %.o, $(SRCL))

%.o: %.c pr_dparser.h parser_advorace.h
	$(CC) -Wall -Wextra -Werror -D EXT_PARSER=1 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJL)
	ar rsc $(NAME) $(OBJL)

clean:
	rm -f $(OBJL)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
