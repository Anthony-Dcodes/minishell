/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:51:05 by omayer            #+#    #+#             */
/*   Updated: 2026/05/22 11:37:57 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELL_H
# define MSHELL_H

# ifndef EXT_PARSER
#  define EXT_PARSER 0
# endif

# define _XOPEN_SOURCE 501

# include "src/types/types.h"
# include "src/pipe/pi_args.h"
# include "src/pipe/pi_dup.h"
# include "src/pipe/pi_redirs.h"
# include "src/pipe/pi_redirsu.h"
# include "src/pipe/pi_redirsv.h"
# include "src/pipe/pi_pipemsg.h"
# include "src/pipe/pi_pipeset.h"
# include "src/pipe/pi_word.h"
# include "src/pipe/pi_worddel.h"
# include "src/shell/sh/sh_config.h"
# include "src/shell/sh/sh_env.h"
# include "src/shell/sh/sh_env2.h"
# include "src/shell/sh/sh_env3.h"
# include "src/shell/sh/sh_files.h"
# include "src/shell/sh/sh_parser.h"
# include "src/shell/sh/sh_filter.h"
# include "src/shell/shw/sh_wenv.h"
# include "src/shell/shw/sh_wenv2.h"
# include "src/shell/shw/sh_wenv3.h"
# include "src/shell/mode/shm_actions.h"
# include "src/shell/mode/shm_exec.h"
# include "src/shell/mode/shm_execu.h"
# include "src/shell/mode/shm_execv.h"
# include "src/shell/mode/shm_execw.h"
# include "src/shell/mode/shm_execx.h"
# include "src/shell/mode/shm_main.h"
# include "src/shell/mode/shm_mainu.h"
# include "src/shell/mode/shm_mainv.h"
# include "src/shell/mode/shm_ps.h"
# include "src/shell/ps/ps_cmd.h"
# include "src/shell/ps/ps_cmdu.h"
# include "src/shell/ps/ps_chars.h"
# include "src/shell/ps/ps_display.h"
# include "src/shell/ps/ps_displayu.h"
# include "src/shell/ps/ps_kpress.h"
# include "src/shell/ps/ps_kpressu.h"
# include "src/shell/ps/ps_process.h"
# include "src/shell/ps/ps_screen.h"
# include "src/types/t_cmd/t_cmd.h"
# include "src/types/t_cmd/t_cmd_fds.h"
# include "src/types/t_fd/t_fdesc.h"
# include "src/types/t_fd/t_fdset.h"
# include "src/types/t_fd/t_fdset_dec.h"
# include "src/types/t_fd/t_fdset_enc.h"
# include "src/types/t_list/t_list.h"
# include "src/types/t_list/t_listu.h"
# include "src/types/t_listex/t_listex.h"
# include "src/types/t_listex/t_listex_file.h"
# include "src/types/t_listex/t_listext.h"
# include "src/types/t_listex/t_listexu.h"
# include "src/types/t_listex/t_listexv.h"
# include "src/types/t_listex/t_listexw.h"
# include "src/types/t_listex/t_listex.h"
# include "src/mshell/mshells.h"
# include "src/mshell/mshellu.h"
# include "src/mshell/mshellw.h"
# include "src/mshell/mshellx.h"
# include "src/mshell/mshelly.h"

# include "const.h"

# include <stdlib.h>
# include <termios.h>
# include <signal.h>
# include <limits.h>

# include "lib/l_lib.h"
# include "lib/l_mini.h"
# include "lib/l_path.h"
# include "lib/l_writef.h"
# include "lib/l_parser.h"
# include "lib/l_dparser.h"
# include "lib/l_sbin.h"

extern size_t	g_is;

# define VG_ENABLED FALSE
# define MSG_ENABLED FALSE
# define INFO_ENABLED FALSE
# define LOG_ENABLED FALSE
# define ENV_VISIBLE TRUE
# define VG_EXEC "/bin/valgrind"

#endif