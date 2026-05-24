# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 09:22:10 by omayer            #+#    #+#              #
#    Updated: 2026/05/22 12:12:49 by oem5491          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../../lib/l_dparser.a
CC := clang
SRCL := pr_dparser_a.c \
		pr_dparser_b.c \
		pr_dparser_c.c \
		pr_dparser.c \

OBJL := $(patsubst %.c, %.o, $(SRCL))

%: %.c
	$(CC) -Wall -Wextra -Werror pr_dparser.h -c $(SRCL)

all: $(NAME)

$(NAME): $(OBJL)
	ar rsc $(NAME) $(OBJL)

clean:
	rm -f $(OBJL)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
