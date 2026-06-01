/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_sbin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/03/21 05:36:10 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_SBIN_H
# define L_SBIN_H

# include <stdlib.h>
# include <sys/wait.h>
# include <termios.h>
# include "../src/types/types.h"

int		ft_sbin_changedir(t_s *s);
int		ft_sbin_showcurrentdir(t_s *s);
int		ft_sbin_writeenv(t_s *s);
int		ft_sbin_export(t_s *s);
int		ft_sbin_unset(t_s *s);
int		ft_sbin_echo(t_s *s, int fd);
int		ft_sbin_exit(t_s *s);

#endif
