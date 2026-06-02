/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_dparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/05/29 21:25:17 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_DPARSER_H
# define L_DPARSER_H

# define _XOPEN_SOURCE 501

int		ft_eparsermain(t_s *s, char *src, t_listex ***dst, char **envp);

#endif