/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshellw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:51:05 by omayer            #+#    #+#             */
/*   Updated: 2026/03/16 09:51:57 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELLW_H
# define MSHELLW_H

# define _XOPEN_SOURCE 501

# include "../../mshell.h"

int		ft_listdupexf(t_s *s, t_listex *dst, char **src);
int		ft_protectinenv(t_s *s, char **envp, char *loc);
int		ft_get_mode(t_s *s, char *af, char **envp, void *f);

#endif