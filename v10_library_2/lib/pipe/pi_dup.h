/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_dup.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:00:44 by omayer            #+#    #+#             */
/*   Updated: 2026/03/22 14:43:43 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PI_DUP_H
# define PI_DUP_H

# include "../../mshell.h"

int	ft_selectdups(t_s *s, t_listex *pipe_list, size_t cmdidx, size_t pipesc);
int	ft_selectdup2in(t_s *s, t_listex *pipe_list, size_t cmdidx);
int	ft_selectdup2out(t_s *s, t_listex *pipe_list, size_t cmdidx, size_t pipesc);

#endif