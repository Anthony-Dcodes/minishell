/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_writef.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:51:05 by omayer            #+#    #+#             */
/*   Updated: 2026/02/05 11:49:27 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_WRITEF_H
# define L_WRITEF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include "../src/types/types.h"

int		ft_writep(t_s *s, int fd, const char *fmt, ...);
int		ft_writeb(t_s *s, char *buf, const char *fmt, ...);

#endif