/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_kpress.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/03/05 14:32:22 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_KPRESS_H
# define PS_KPRESS_H

# include "../../../mshell.h"
# include <signal.h>

int		ft_onspecialcharpress2(t_s *s, char *buffer, int *idx);
int		ft_oncharpress2(t_s *s, char *buffer, int *idx);
int		ft_decreaselevel(t_s *s);
int		ft_keypressselector2(t_s *s, char *buffer, int *idx);
int		ft_changeterminal2(t_s *s, t_termios *t_old);

#endif
