/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_wenv2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/02 22:23:32 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_WENV2_H
# define SH_WENV2_H

# include "sh_wenv.h"
# include "../../../mshell.h"
# include <fcntl.h>

int		ft_wgetenv2(t_s *s, char **env, char *var, char *value);
int		ft_wgetenv2d(t_s *s, char **env, char *var, char **v);
int		ft_wsetenvint2(t_s *s, t_listex *env, char *var, int nbr);
int		ft_wgetenvint2(t_s *s, size_t *r, char **env, char *var);
int		ft_wsetenvstep2(t_s *s, t_listex *env, char *var, int step);

#endif