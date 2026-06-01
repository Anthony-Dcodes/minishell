/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:17:33 by oem5491           #+#    #+#             */
/*   Updated: 2026/02/05 13:16:10 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_DISPLAY_H
# define PS_DISPLAY_H

# define _XOPEN_SOURCE 501

# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include "../../../mshell.h"

int		ft_displaybuffer(t_s *s);
int		ft_displaycontent(t_s *s);

#endif
