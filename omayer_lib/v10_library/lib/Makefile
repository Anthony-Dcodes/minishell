# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omayer <omayer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 09:22:10 by omayer            #+#    #+#              #
#    Updated: 2025/12/18 15:26:20 by omayer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := mshell
CC := clang
HLIB := lib/l_lib.a \
		lib/l_path.a \
		lib/l_writef.a \
		lib/l_parser.a \
		lib/l_sbin.a
HDRS := mshell.h \
		src/types/types.h \
		const.h
SRCL := mshellu.c
SRCH := src/pipe/pi_args.c \
		src/pipe/pi_redirs.c \
		src/pipe/pi_redirsu.c \
		src/pipe/pi_pipeset.c \
		src/shell/sh_config.c \
		src/shell/sh_env2.c \
		src/shell/sh_env.c \
		src/shell/sh_parser.c \
		src/shell/mode/shm_exec.c \
		src/shell/mode/shm_execu.c \
		src/shell/mode/shm_main.c \
		src/shell/mode/shm_ps.c \
		src/shell/ps/ps_cmd.c \
		src/shell/ps/ps_cmdu.c \
		src/shell/ps/ps_chars.c \
		src/shell/ps/ps_kpress.c \
		src/shell/ps/ps_process.c \
		src/shell/ps/ps_screen.c \
		src/types/t_cmd/t_cmd.c \
		src/types/t_cmd/t_cmd_fds.c \
		src/types/t_cmd/t_cmd_fdsu.c \
		src/types/t_fd/t_fdesc.c \
		src/types/t_fd/t_fdset.c \
		src/types/t_fd/t_fdset_dec.c \
		src/types/t_fd/t_fdset_enc.c \
		src/types/t_list/t_list.c \
		src/types/t_list/t_listu.c \
		src/types/t_listex/t_listex.c \
		src/types/t_listex/t_listex_file.c \
		src/types/t_listex/t_listexu.c \
		src/types/t_listex/t_listexv.c

OBJL := $(patsubst %.c, %.o, $(SRCL))

%: %.c mshell.h $(HDRS)
	$(CC) -Wall -Wextra -Werror -c $(HDRS) $(SRCL)

OBJH := $(patsubst %.c, %.o, $(SRCH))

%: %.c $(HDRS) %.h
	$(CC) -Wall -Wextra -Werror -c $(HDRS) $(SRCH)

all: $(NAME)

$(NAME): mshell.c $(HDRS) $(OBJL) $(OBJH)
	$(CC) -Wall -Wextra -ggdb mshell.c $(OBJL) $(OBJH) \
	$(HLIB) -lm -o $(NAME)

clean:
	rm -f $(OBJL) $(OBJH)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
