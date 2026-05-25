# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: advorace <advorace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 09:22:10 by omayer            #+#    #+#              #
#    Updated: 2026/05/25 15:19:09 by advorace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
CC := clang
HLIB := lib/l_lib.a \
		lib/l_mini.a \
		lib/l_path.a \
		lib/l_writef.a \
		lib/l_parser.a \
		lib/l_dparser.a \
		lib/l_sbin.a
HDRSLIB := libsrc/echo/ft_writef.h \
		   libsrc/lib/lib.h \
		   libsrc/mini/mini.h \
		   libsrc/parser/pr_parser.h \
		   libsrc/path/path.h \
		   libsrc/sbin/sbin.h 
HDRS := mshell.h \
		src/types/types.h \
		const.h

all: libbuild srcbuild $(NAME)

libbuild:
	cd libsrc/echo && make
	cd libsrc/lib && make
	cd libsrc/mini && make
	cd libsrc/parser && make
	cd libsrc/dparser && make
	cd libsrc/path && make
	cd libsrc/sbin && make

libsrc: libbuild

srcbuild:
	cd src && make

librarybuild: mshell.c $(HDRS)
	$(CC) -Wall -Wextra -Werror -ggdb -D EXT_PARSER=0 mshell.c \
	-Wl,--start-group lib/l_mshell.a lib/l_shell.a lib/l_pipe.a lib/l_types.a $(HLIB) -Wl,--end-group \
	-lm -o $(NAME)

$(NAME): mshell.c $(HDRS) srcbuild libbuild
	$(CC) -Wall -Wextra -Werror -ggdb -D EXT_PARSER=0 mshell.c \
	-Wl,--start-group lib/l_mshell.a lib/l_shell.a lib/l_pipe.a lib/l_types.a $(HLIB) -Wl,--end-group \
	-lm -o $(NAME)

clean:
	cd src && make clean

fcleanlib:
	cd libsrc/echo && make fclean
	cd libsrc/lib && make fclean
	cd libsrc/mini && make fclean
	cd libsrc/parser && make fclean
	cd libsrc/dparser && make fclean
	cd libsrc/path && make fclean
	cd libsrc/sbin && make fclean

cleanlib:
	cd libsrc/echo && make clean
	cd libsrc/lib && make clean
	cd libsrc/mini && make clean
	cd libsrc/parser && make clean
	cd libsrc/dparser && make clean
	cd libsrc/path && make clean
	cd libsrc/sbin && make clean

srcclean:
	cd src && make clean

srcfclean:
	cd src && make fclean

srcre:
	cd src && make re

fclean: clean
	cd libsrc/echo && make fclean
	cd libsrc/lib && make fclean
	cd libsrc/mini && make fclean
	cd libsrc/parser && make fclean
	cd libsrc/dparser && make fclean
	cd libsrc/path && make fclean
	cd libsrc/sbin && make fclean
	cd src && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libbuild libsrc cleanlib fcleanlib srcbuild srcclean srcfclean srcre librarybuild
