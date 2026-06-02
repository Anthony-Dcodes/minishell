/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_screen.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:39:06 by oem5491           #+#    #+#             */
/*   Updated: 2026/02/05 21:46:09 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SCREEN_H
# define PS_SCREEN_H

# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include "../../../mshell.h"
# include "sys/ioctl.h"

int		ft_scrmoveleft2(t_s *s, size_t len, int nbrs);
int		ft_scrmoveright2(t_s *s, size_t len);
int		ft_getscreenpos(t_s *s, size_t postfix);
int		ft_screenupdate(t_s *s);
int		ft_displayclear(t_s *s, int size);

#endif