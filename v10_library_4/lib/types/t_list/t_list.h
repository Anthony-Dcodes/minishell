/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:10:54 by omayer            #+#    #+#             */
/*   Updated: 2026/02/19 08:22:56 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H
# define T_LIST_H

# include "../../../mshell.h"
# include <string.h>

size_t	ft_listlen2(t_s *s, char **src);
int		ft_listdup(t_s *s, char ***dst, char **src, size_t len);
int		ft_listadd2(t_s *s, char ***dstlist, char **srclist, char *src);
int		ft_listreplace2(t_s *s, char ***dst, char *src, size_t idx);
int		ft_listfree2(t_s *s, char **src, size_t len);

#endif