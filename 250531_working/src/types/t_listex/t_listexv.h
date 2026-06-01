/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_listexv.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:39:39 by omayer            #+#    #+#             */
/*   Updated: 2026/02/12 14:15:12 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LISTEXV_H
# define T_LISTEXV_H

# include "../../../mshell.h"

int		ft_listdupex2(t_s *s, t_listex *dst, char **src);
int		ft_deccmdlist(t_s *s, size_t *csize, t_listex *envp, size_t *idx);
int		ft_sortlistex(t_s *s, t_listex *list, t_listex *res);

#endif