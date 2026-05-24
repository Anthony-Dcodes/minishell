/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/03 10:57:54 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

# define _XOPEN_SOURCE 501

# include "../../../mshell.h"
# include <fcntl.h>

int	ft_findinenv2(t_s *s, t_listex *env, char *var, size_t *findidx);
int	ft_setenv2(t_s *s, t_listex *env, char *var, char *value);
int	ft_unsetenv2(t_s *s, t_listex **env, char *var);

#endif