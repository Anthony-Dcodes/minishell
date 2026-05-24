/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_listex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/04 10:02:17 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LISTEX_H
# define T_LISTEX_H

# include "../../../mshell.h"

int		ft_newlistex2(t_s *s, t_listex *list, size_t words, int init);
int		ft_newlistexarr2(t_s *s, t_listex ***list, size_t size);
int		ft_unloadlistex2(t_s *s, t_listex *list);
int		ft_listcopyex2n(t_s *s, t_listex *dst, t_listex *src, char qpsir[5]);

#endif
