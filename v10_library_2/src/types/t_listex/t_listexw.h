/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_listexw.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:39:39 by omayer            #+#    #+#             */
/*   Updated: 2026/03/18 17:41:22 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LISTEXW_H
# define T_LISTEXW_H

# include "../../../mshell.h"

int		ft_connectex2(t_s *s, char *r, t_listex *list, char sep);
int		ft_strextractex2(t_s *s, t_listex *r, char *src, char c);
int		ft_listcopyex2(t_s *s, t_listex *dst, t_listex *src, size_t i);
int		ft_excharex2(t_s *s, t_listex *src, char a, char b);

#endif