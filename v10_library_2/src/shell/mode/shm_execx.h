/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_execx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/03/03 11:36:29 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHM_EXECX_H
# define SHM_EXECX_H

# include "../../../mshell.h"
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

int		ft_sendreversemsg2(t_s *s, int rpipe[2]);
int		ft_getreversemsg2(t_s *s, int rpipe[2]);
int		ft_decreaseshlevel(t_s *s);

#endif
