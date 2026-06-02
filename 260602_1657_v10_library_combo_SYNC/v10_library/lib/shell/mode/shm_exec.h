/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_exec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/01/23 14:48:13 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHM_EXEC_H
# define SHM_EXEC_H

# include "../../../mshell.h"
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

int		ft_m_exec(t_s *s);
int		ft_preparerun(t_s *s);
int		ft_runwpath(t_s *s, t_listex *filterenv);
int		ft_runcmd(t_s *s);
int		ft_f_exec(t_s *s);

#endif
