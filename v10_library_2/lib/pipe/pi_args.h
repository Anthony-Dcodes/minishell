/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_args.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/02/21 22:12:53 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PI_ARGS_H
# define PI_ARGS_H

# include "pi_redirs.h"

int		ft_filtersource2(t_s *s, char **r, t_listex *src);
int		ft_getpipeargfs2(t_s *s, char **dst, t_listex *src);

#endif