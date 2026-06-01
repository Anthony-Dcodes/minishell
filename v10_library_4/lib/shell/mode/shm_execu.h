/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_execu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/02/20 08:29:55 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHM_EXECU_H
# define SHM_EXECU_H

# include "../../../mshell.h"
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

int		ft_execve2(t_s *s, char *mode, int envenabled);
int		ft_detectexit2(t_s *s, size_t *err);
int		ft_selectnextcmd2(t_s *s, size_t idx, size_t cmdsize);
int		ft_protectbuffer(t_s *s);

#endif
