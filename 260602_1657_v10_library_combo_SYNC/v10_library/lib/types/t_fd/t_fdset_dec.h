/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fdset_dec.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:02:13 by omayer            #+#    #+#             */
/*   Updated: 2026/01/14 19:24:01 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FDSET_DEC_H
# define T_FDSET_DEC_H

# include "../../../mshell.h"

int		ft_decfdesc(t_s *s, t_fdesc *fdesc, char *src, int *type);
int		ft_decfdset(t_s *s, t_fdset *result, char *src);

#endif