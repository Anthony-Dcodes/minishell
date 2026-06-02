/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_word.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/18 09:26:53 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PI_WORD_H
# define PI_WORD_H

# include "../../mshell.h"

int		ft_prepareword(t_s *s, char **r, t_listex *src, char *del);
int		ft_extractredirword2(t_s *s, t_listex *src, int *type, t_fdesc *fdesc);

#endif