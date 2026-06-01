/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_redirsv.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/04 11:08:24 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PI_REDIRSV_H
# define PI_REDIRSV_H

# include "../../mshell.h"

int		ft_setredir2(t_s *s, t_fdset *fdset, t_fdesc fdesc);
int		ft_extracthere(t_s *s, char *item, t_fdesc *fdesc, size_t startl);

#endif