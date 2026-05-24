/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fdesc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:33:58 by omayer            #+#    #+#             */
/*   Updated: 2026/01/14 23:42:04 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FDESC_H
# define T_FDESC_H

# include "../../../mshell.h"

int		fpdesccopy(t_s *s, t_fdesc **result, t_fdesc **src);
int		fpdescadd(t_s *s, t_fdesc ***dst, t_fdesc **src, t_fdesc add);
int		fpdescfree(t_s *s, t_fdesc **dst);

#endif