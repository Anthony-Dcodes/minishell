/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshelly.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:51:05 by omayer            #+#    #+#             */
/*   Updated: 2026/02/20 08:50:11 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELLY_H
# define MSHELLY_H

# include "../../mshell.h"

int		fe(void *s, int f);
int		fp(void *s, int f, int err);
int		fb(void *s, int f, int err);
int		ft_fixldpath(t_s *s);

#endif