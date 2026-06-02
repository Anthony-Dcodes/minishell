/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshellx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:21:55 by oem5491           #+#    #+#             */
/*   Updated: 2026/03/13 17:12:49 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELLX_H
# define MSHELLX_H

# include "../../mshell.h"

int		ft_getmaindata(t_s *s, void *f);
int		ft_initpipesetup(t_s *s);
int		ft_getcurrentpath2(t_s *s, char *result, char *argvfirst);

#endif