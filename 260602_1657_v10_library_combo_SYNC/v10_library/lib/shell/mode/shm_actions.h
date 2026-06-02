/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_actions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/03/09 15:37:48 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHM_ACTIONS_H
# define SHM_ACTIONS_H

# define _XOPEN_SOURCE 501

# include "../../../mshell.h"
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

int		ft_setactions(t_s *s, char *iqwarwsf, void *f);
int		ft_setdefaultactions(t_s *s, int range);
int		ft_resetactions(t_s *s);
int		ft_getpid2(t_s *s, int *r, void *f);

#endif
