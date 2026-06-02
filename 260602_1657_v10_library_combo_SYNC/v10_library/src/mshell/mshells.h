/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshells.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:51:05 by omayer            #+#    #+#             */
/*   Updated: 2026/03/16 09:50:08 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELLS_H
# define MSHELLS_H

# include "../../mshell.h"

int		ft_initlolpid(t_s *s, char **envp);
int		ft_savesenderid(t_s *s, void *f, int direct, int c);
int		ft_loadsenderid(t_s *s, int *ps_id, int *c);

#endif