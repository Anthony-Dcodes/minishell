/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/02/27 16:06:36 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV3_H
# define SH_ENV3_H

# include "sh_env.h"
# include "../../../mshell.h"
# include <fcntl.h>

int		ft_getlenvint2(t_s *s, size_t *r, char *var);
int		ft_prepareenv2s(t_s *s, char *var, char *c, char *value);
int		ft_findinpath2(t_s *s, char **r, char *filename);
int		ft_bufferinsert2d(t_s *s, char **buffer, char *value, size_t vsize);
int		ft_bufferinserte2d(t_s *s, char **buffer, char *value, size_t vsize);

#endif