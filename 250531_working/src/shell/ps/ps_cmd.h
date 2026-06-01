/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/03/21 05:56:33 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CMD_H
# define PS_CMD_H

# include "../../../mshell.h"
# include <signal.h>

int		ft_loadhistory2(t_s *s, t_listex *env, t_listex *cmdh);
int		ft_savehistory2(t_s *s, t_listex *env, t_listex cmdh);
int		ft_updatehistory2(t_s *s, t_listex *env);
int		ft_loadprevhistorycmd2(t_s *s, int *idx);
int		ft_loadnexthistorycmd2(t_s *s, int *idx);

#endif
