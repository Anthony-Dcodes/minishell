/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshellu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:51:05 by omayer            #+#    #+#             */
/*   Updated: 2026/02/18 15:49:36 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELLU_H
# define MSHELLU_H

# include "../../mshell.h"

int		ft_execloadcmds2(t_s *s);
int		ft_getpaths2(t_s *s, char *argvfirst);
int		ft_getselfpath2(t_s *s, char *result, char *argvfirst);

#endif