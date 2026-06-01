/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_mainu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/02/18 11:18:36 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHM_MAINU_H
# define SHM_MAINU_H

# define _XOPEN_SOURCE 501

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include "../../../mshell.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <errno.h>

int		ft_sendmsg2(t_s *s, t_listex source, int rpipe[2]);
int		ft_getmsg2(t_s *s, t_listex *target, int rpipe[2]);

#endif
