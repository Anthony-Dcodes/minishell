/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmdu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/02/19 07:29:28 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CMDU_H
# define PS_CMDU_H

# include "../../../mshell.h"
# include <signal.h>

int		ft_resetcmd2(t_s *s);
int		ft_gotostartcmd2(t_s *s);
int		ft_writelog(t_s *s);
int		ft_inithistory(t_s *s);
int		ft_reducehistory(t_s *s, t_listex *cmdh, t_listex *cmdh_new);

#endif
