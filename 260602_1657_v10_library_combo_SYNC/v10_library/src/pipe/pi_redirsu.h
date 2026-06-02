/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_redirsu.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/02/04 22:11:16 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PI_REDIRSU_H
# define PI_REDIRSU_H

# include "../../mshell.h"

int		ft_setout2(t_s *s, char *item, t_fdesc *fdesc, size_t startr);
int		ft_setouta2(t_s *s, char *item, t_fdesc *fdesc, size_t startr);
int		ft_setin2(t_s *s, char *item, t_fdesc *fdesc, size_t startl);
int		ft_setindel2(t_s *s, char *item, t_fdesc *fdesc, size_t startl);

#endif