/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fdset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:02:13 by omayer            #+#    #+#             */
/*   Updated: 2026/01/14 19:24:01 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FDSET_H
# define T_FDSET_H

# include "../../../mshell.h"

int		fpdsetinit(t_s *s, t_fdset *dst);
int		fpdsetadd(t_s *s, t_fdset *dst, t_fdesc src, char type);
int		fpdsetfree(t_s *s, t_fdset *dst);

#endif