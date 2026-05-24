/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chars.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/01/19 10:28:20 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHARS_H
# define PS_CHARS_H

# include "../../../mshell.h"
# include <signal.h>

int		ft_prepareinsert(t_s *s, t_ccmd *a, char *buf, size_t *pos);
int		ft_insertchar2(t_s *s, char *buf, char c, size_t *pos);
int		ft_removechar2(t_s *s, char *buf, size_t *pos, int backspace);

#endif
