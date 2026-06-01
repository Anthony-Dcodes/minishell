/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_ps.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/03/13 13:16:23 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHM_PS_H
# define SHM_PS_H

# define _XOPEN_SOURCE 501

# include <stdlib.h>
# include "../../../mshell.h"
# include <sys/wait.h>
# include <termios.h>
# include <stdio.h>

int		ft_psrun(t_s *s, t_termios *t_old, void *f);
int		ft_m_ps(t_s *s, t_termios *t_old, void *f);

#endif
