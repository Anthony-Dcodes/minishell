/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:46:47 by omayer            #+#    #+#             */
/*   Updated: 2026/03/22 16:29:25 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define _XOPEN_SOURCE 501

# include <string.h>
# include "../../const.h"
# include <termios.h>

typedef struct sigaction	t_act;
typedef struct termios		t_termios;

typedef struct s_listex
{
	char		**items;
	char		*xattr_qc;
	char		*xattr_pc;
	char		*xattr_sc;
	char		*xattr_pidx;
	char		*xattr_rc;
	size_t		size;
}	t_listex;

typedef struct s_v
{
	void		**items;
	size_t		size;
}	t_v;

typedef struct s_fdesc
{
	int			in_fd;
	int			file_fd;
	char		path[SLINESIZE];
	char		here[ENVSIZE];
	char		del[SLINESIZE];
	char		active;
}	t_fdesc;

typedef struct s_fdset
{
	t_fdesc		**ins;
	size_t		insc;
	t_fdesc		**ins_del;
	size_t		ins_delc;
	t_fdesc		**outs_a;
	size_t		outs_ac;
	t_fdesc		**outs_t;
	size_t		outs_tc;
}	t_fdset;

typedef struct s_cmd
{
	char		*in_cmd;
	char		self[SLINESIZE];
	char		config[SLINESIZE];
	char		history[SLINESIZE];
	char		path[SLINESIZE];
	char		here[ENVSIZE];
	char		delimiter[SLINESIZE];
	t_fdset		fdset;
	int			file_fd_in;
	int			file_fd_out;
	int			in_fd_in;
	int			in_fd_out;
	int			revpipe[2];
	int			sh_errno;
}	t_cmd;

typedef struct s_process
{
	t_listex		lenv;
	t_listex		ldata;
	t_listex		lcmd;
	t_listex		lcmdh;
	char			cwd[SLINESIZE];
	char			cmd[SLINESIZE];
	size_t			cmd_len;
	size_t			cmd_pos;
	size_t			cmd_line;
	int				scr_col;
	int				scr_row;
	int				scr_pos;
	t_listex		arg;
	t_termios		t_old;
	char			sh_mode[SLINESIZE];
	pid_t			pid_get;
	pid_t			pid_self;
	t_cmd			tcmd;
}	t_process;

typedef struct s_cgroup
{
	size_t		gid;
	char		gchar;
	int			open;
	size_t		glen;
	size_t		gstart;
}	t_cgroup;

typedef struct s_pipe_arg
{
	size_t		i;
	size_t		pipe_idx;
	size_t		seg_idx;
}	t_pipe_arg;

typedef struct s_exp_arg
{
	size_t		i;
	size_t		len;
	size_t		from;
	size_t		srclen;
	size_t		bpos;
	size_t		len2;
}	t_exp_arg;

typedef struct s_command
{
	t_cgroup		**groups;
	size_t			g_size;
	t_listex		grouped;
	t_listex		p_sgl;
	t_listex		p_dbl;
}	t_command;

typedef struct s_ccmd
{
	char			*c_prefix;	
	char			*c_path;
	char			*c_postfix;
	t_listex		c_pargv;
	char			*c_cwd;
	char			pathv;
	char			*ccmd_orig_cmd;
	size_t			ccmd_orig_cmd_pos;
	char			*ccmd_filter;
	char			fenabled;
}	t_ccmd;

typedef struct s_envarg
{
	char		*var;
	char		*c;
	char		*value;
}	t_envarg;

typedef struct s_smem
{
	char				msg_buffer[ARG_STR_SIZE];
	char				pac_buffer[PAC_BSIZE];
}	t_smem;

typedef struct s_cmem
{
	char				pac_buffer[PAC_BSIZE];
}	t_cmem;

typedef struct s_setup
{
	t_process	*p;
	t_command	*cmd;
	t_smem		smem;
	t_cmem		cmem;
	size_t		sh_lvl;
	int			scr_col;
	int			scr_row;
	int			scr_x;
	int			scr_y;
	int			scr_line;
	int			scr_line_prev;
	size_t		dbufferpos;
	char		*dbuffer;
	char		*sbuffer;
	int			is_atty;
	int			here;
	int			herectrlc;
	size_t		*space_idx;
	size_t		*size;
	size_t		replace;
	size_t		*len;
	char		*set;
	int			type;
	char		**r;
	char		c;
	size_t		i;
	int			idx;
	void		*fcatch;
	int			(*f)(void *, int, int);
	int			(*e)(void *, int);
	int			(*fcol)(void *, int, void *, int);
	int			mread[2];
	int			mwrite[2];
	t_listex	maindata;
	t_listex	mainlenv;
	int			pid_main;
	int			pid_ps;
	int			pid_exec;
	int			ie;
	int			logfile;
	size_t		files;
	t_exp_arg	*exp;
	char		*segitem;
	size_t		echolen;
	int			pidpipe[2];
	int			ext_parser;
	int			direct_parser;
	int			ret;
}	t_s;

typedef struct s_sbinarg
{
	size_t			i;
	t_listex		*lenv;
	t_listex		arg;
	int				r;
	t_s				b;
	size_t			words;
	size_t			eqcount;
	size_t			len;
	char			result[SLINESIZE];
}	t_sbinarg;

#endif