/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_displayu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:17:33 by oem5491           #+#    #+#             */
/*   Updated: 2026/03/21 06:03:17 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_DISPLAYU_H
# define PS_DISPLAYU_H

# define _XOPEN_SOURCE 501

# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include "../../../mshell.h"

int		ft_getcwd(t_s *s, char **r);
int		ft_display_process2(t_s *s, int direct);

#endif
