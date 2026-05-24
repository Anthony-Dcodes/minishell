/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/19 07:47:45 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_PARSER_H
# define L_PARSER_H

# define _XOPEN_SOURCE 501

# include "l_lib.h"
# include "../src/shell/sh/sh_env.h"
# include "../mshell.h"
# include "../src/types/t_list/t_list.h"
# include "../src/types/t_listex/t_listex.h"
# include "../src/types/t_listex/t_listexu.h"

int		ft_parsermain(t_s *s, char *src, t_listex ***dst);

#endif