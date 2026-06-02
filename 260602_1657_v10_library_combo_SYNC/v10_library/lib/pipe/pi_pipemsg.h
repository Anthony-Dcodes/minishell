/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_pipemsg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:00:44 by omayer            #+#    #+#             */
/*   Updated: 2026/02/10 10:53:04 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PI_PIPEMSG_H
# define PI_PIPEMSG_H

# include "../../mshell.h"

int		ft_getmsgfd(t_s *s, int *dst, char *src, char fdin);
int		ft_decpipemsg(t_s *s);
int		ft_encpipe2(t_s *s, char **r, int pipes[2]);
int		ft_encpipemsg2(t_s *s);

#endif