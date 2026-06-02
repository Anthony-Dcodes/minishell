/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/02/27 16:06:29 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV2_H
# define SH_ENV2_H

# include "sh_env.h"
# include "../../../mshell.h"
# include <fcntl.h>

int		ft_getenv2(t_s *s, char **env, char *var, char *value);
int		ft_getenv2d(t_s *s, char **env, char *var, char **v);
int		ft_setenvint2(t_s *s, t_listex *env, char *var, int nbr);
int		ft_getenvint2(t_s *s, size_t *r, char **env, char *var);
int		ft_setenvstep2(t_s *s, t_listex *env, char *var, int step);

#endif