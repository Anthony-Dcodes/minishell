/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_execv.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/03/07 05:58:37 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHM_EXECV_H
# define SHM_EXECV_H

# include "../../../mshell.h"
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

int		ft_getreversemsg2result(t_s *s, int ret);
int		ft_filterenv(t_s *s, t_listex *dst, t_listex src, char *fr);
int		ft_filterenvrun(t_s *s, t_listex *dst, t_listex src);
int		ft_runhere(t_s *s);
int		ft_nop(t_s *s);

#endif
