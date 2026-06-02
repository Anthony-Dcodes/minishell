/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:18:01 by omayer            #+#    #+#             */
/*   Updated: 2026/03/21 05:58:28 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PROCESS_H
# define PS_PROCESS_H

# define _XOPEN_SOURCE 501

# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include "../../../mshell.h"

int		ft_getprocess_cmd2(t_s *s, char *cwd);
int		ft_gethere_cmd2(t_s *s, t_listex *here, char *delimiter);

#endif
