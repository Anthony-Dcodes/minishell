/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_fds.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:40:11 by omayer            #+#    #+#             */
/*   Updated: 2026/01/23 10:07:33 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CMD_FDS_H
# define T_CMD_FDS_H

# include "../../../mshell.h"
# include <fcntl.h>

int		ft_getactivefdsin(t_s *s, t_cmd *cmd);
int		ft_getactivefdsout(t_s *s, t_cmd *cmd);
int		ft_activatefdsin(t_s *s, t_cmd *cmd);
int		ft_activatefdsout(t_s *s, t_cmd *cmd);

#endif