/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mini.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:53:06 by omayer            #+#    #+#             */
/*   Updated: 2026/03/21 05:13:03 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_MINI_H
# define L_MINI_H

# define _XOPEN_SOURCE 501

# include <string.h>
# include <signal.h>
# include "../mshell.h"

int			ft_miniclientmain(t_s *s, char *in_mask, char *out_mask);

#endif