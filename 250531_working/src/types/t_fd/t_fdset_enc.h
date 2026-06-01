/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fdset_enc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:02:13 by omayer            #+#    #+#             */
/*   Updated: 2026/01/14 19:24:01 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FDSET_ENC_H
# define T_FDSET_ENC_H

# include "../../../mshell.h"
# include <unistd.h>

int		ft_encfdesc(t_s *s, char **r, t_fdesc *fdesc, int type);
int		ft_encfdsettype(t_s *s, t_listex *list, t_fdesc **typearr, int type);
int		ft_encfdsetfs(t_s *s, t_fdset *fdset);
int		ft_encfdset2(t_s *s, char **r, t_fdset *dst);

#endif