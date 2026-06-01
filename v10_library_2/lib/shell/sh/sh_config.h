/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/02/27 16:06:05 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_CONFIG_H
# define SH_CONFIG_H

# define _XOPEN_SOURCE 501

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../../../mshell.h"
# include <sys/wait.h>

int		ft_shinitaction(t_s *s, t_act *action, void *f, int act);
int		ft_shinit2(t_s *s, void *f, int enable);

#endif