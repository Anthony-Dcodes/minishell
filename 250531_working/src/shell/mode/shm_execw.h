/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_execw.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/02/19 07:13:52 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHM_EXECW_H
# define SHM_EXECW_H

# include "../../../mshell.h"
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

int		ft_entersafemode(t_s *s);
int		ft_runsbin2(t_s *s, int fd);

#endif
