/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/19 10:16:38 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H

# include "../../../mshell.h"

int		ft_parsecmd(t_s *s, char *src, t_listex *dst);
int		ft_cleandoublelist(t_s *s, t_listex **src);

#endif