/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_wenv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/03 11:07:11 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_WENV_H
# define SH_WENV_H

# define _XOPEN_SOURCE 501

# include "../../../mshell.h"
# include <fcntl.h>

int	ft_wsetenv2(t_s *s, t_listex *env, char *var, char *value);
int	ft_wunsetenv2(t_s *s, t_listex **env, char *var);

#endif