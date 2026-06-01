/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_redirs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/02/21 22:15:04 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PI_REDIRS_H
# define PI_REDIRS_H

# include "../../mshell.h"

int		ft_resetactiveonins2(t_s *s, t_fdset *fdset);
int		ft_resetactiveonouts2(t_s *s, t_fdset *fdset);
int		ft_extractredirsw2(t_s *s, t_listex *src, t_fdset *fdset, size_t *i);
int		ft_extractredirs2(t_s *s, char **r, t_listex *src);

#endif