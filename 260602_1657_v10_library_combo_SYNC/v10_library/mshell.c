/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:25:59 by omayer            #+#    #+#             */
/*   Updated: 2026/05/21 11:10:04 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 501

#include "mshell.h"

size_t	g_is;

static void	ft_catch(int sig, siginfo_t *siginfo, void *ptr)
{
	g_is = sig + siginfo->si_pid * SOFF;
	siginfo = NULL;
	ptr = NULL;
	if ((siginfo) && (ptr))
		siginfo = NULL;
}

static int	ft_getmainpipesc(t_s *s)
{
	if (s == NULL)
		return (ENULL);
	s->f(s, ft_getenvint2(s, (size_t *)&s->mread[P_READ],
			s->p->lenv.items, L_MREAD_F), s->ie++);
	s->f(s, ft_getenvint2(s, (size_t *)&s->mread[P_WRITE],
			s->p->lenv.items, L_MREAD_S), s->ie++);
	s->f(s, ft_getenvint2(s, (size_t *)&s->mwrite[P_READ],
			s->p->lenv.items, L_MWRITE_F), s->ie++);
	s->f(s, ft_getenvint2(s, (size_t *)&s->mwrite[P_WRITE],
			s->p->lenv.items, L_MWRITE_S), s->ie++);
	s->f(s, ft_getmaindata(s, &ft_catch), s->ie++);
	return (SUCCESS);
}

static int	ft_getmainpipes(t_s *s)
{
	if (s == NULL)
		return (ENULL);
	s->p->pid_self = s->p->pid_get;
	s->pid_ps = ERROR;
	s->pid_exec = ERROR;
	s->f(s, ft_setdefaultactions(s, SIGRTMAX), FALSE);
	if (s->f(s, ft_equal2(s, s->p->sh_mode, C_EXEC, TRUE), FALSE))
	{
		if (s->p->pid_get == 0)
			s->f(s, ft_getpid2(s, &s->pid_exec, s->fcatch), s->ie++);
		s->f(s, ft_setactions(s, "00000000", &ft_catch), s->ie++);
	}
	else if (s->f(s, ft_equal2(s, s->p->sh_mode, C_PS, TRUE), FALSE))
	{
		s->f(s, ft_getpid2(s, &s->pid_ps, s->fcatch), s->ie++);
		s->f(s, ft_setactions(s, "00100000", &ft_catch), s->ie++);
	}
	else if (s->p->pid_get != PROCESS_PID)
		s->f(s, ft_setactions(s, "00011000", &ft_catch), s->ie++);
	else
		s->f(s, ft_setactions(s, "00000000", NULL), s->ie++);
	s->f(&s, ft_getmainpipesc(s), s->ie++);
	return (SUCCESS);
}

static int	ft_mainc(t_s *s)
{
	if (s == NULL)
		return (ENULL);
	if (s->f(s, ft_equal2(s, s->p->sh_mode, C_EXEC, TRUE), FALSE))
		s->f(s, ft_execloadcmds2(s), s->ie++);
	if ((s->f(s, ft_equal2(s, s->p->sh_mode, C_MAIN, TRUE), FALSE))
		&& (s->p->pid_get != PROCESS_PID))
		s->f(s, ft_m_main(s), s->ie++);
	else if (s->f(s, ft_equal2(s, s->p->sh_mode, C_PS, TRUE), FALSE))
		s->f(s, ft_m_ps(s, &s->p->t_old, &ft_catch), s->ie++);
	else if ((s->f(s, ft_equal2(s, s->p->sh_mode, C_EXEC, TRUE), FALSE))
		&& (s->p->pid_get != PROCESS_PID))
		s->f(s, ft_m_exec(s), s->ie++);
	else if (s->f(s, ft_equal2(s, s->p->sh_mode, C_MAIN, TRUE), FALSE))
		s->f(s, ft_f_main(s), s->ie++);
	else if (s->f(s, ft_equal2(s, s->p->sh_mode, C_EXEC, TRUE), FALSE))
		s->f(s, ft_f_exec(s), s->ie++);
	return (SUCCESS);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_s				s;
	t_process		p;

	s.ie = 0;
	g_is = 0;
	s.p = &p;
	s.f = fp;
	s.e = fe;
	s.fcol = &ft_collector;
	s.fcatch = &ft_catch;
	s.pid_main = 0;
	s.ext_parser = EXT_PARSER;
	s.direct_parser = FALSE;
	s.f(&s, ft_get_mode(&s, argv[0], envp, &ft_catch), s.ie++);
	if (((s.f(&s, ft_equal2(&s, s.p->sh_mode, C_MAIN, TRUE), FALSE))
			|| (s.f(&s, ft_equal2(&s, s.p->sh_mode, C_EXEC, 1), 0))) && (argc))
		s.p->pid_get = s.f(&s, (int)fork(), s.ie++);
	s.f(&s, ft_getmainpipes(&s), s.ie++);
	s.f(&s, ft_mainc(&s), FALSE);
	s.fcol(&s, COL_EXIT, NULL, EXIT_NOW);
}
