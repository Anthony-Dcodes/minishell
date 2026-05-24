/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_main.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/03/21 06:09:25 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHM_MAIN_H
# define SHM_MAIN_H

# define _XOPEN_SOURCE 501

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include "../../../mshell.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <errno.h>

int		ft_m_main(t_s *s);
int		ft_f_main(t_s *s);

#endif
