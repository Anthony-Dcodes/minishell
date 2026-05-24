/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_listexu.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/02/21 21:31:50 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LISTEXU_H
# define T_LISTEXU_H

# include "../../../mshell.h"

int		ft_listaddex2(t_s *s, t_listex *list, char *src);
int		ft_listaddexint2(t_s *s, t_listex *list, int nbr);
int		ft_getlistsize(t_s *s, char **list, size_t start, size_t *resultlen);
int		ft_listremapex(t_s *s, t_listex **dst, t_listex *src, char qpsir[5]);

#endif
