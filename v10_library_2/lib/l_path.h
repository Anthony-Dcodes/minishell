/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_path.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:27:59 by omayer            #+#    #+#             */
/*   Updated: 2026/02/18 13:53:14 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_PATH_H
# define L_PATH_H

# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

# include "../src/types/types.h"

int		ft_getnextfile(t_s *s, int scrpos, char *cwd);

#endif