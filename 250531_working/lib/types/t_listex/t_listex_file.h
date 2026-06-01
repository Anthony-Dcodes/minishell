/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_listex_file.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/01/22 12:43:59 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LISTEX_FILE_H
# define T_LISTEX_FILE_H

# include "../../../mshell.h"
# include <fcntl.h>

int		ft_loadlistex2(t_s *s, t_listex *list, char *path);
int		ft_loadlistexfd2(t_s *s, t_listex *list, int fd);
int		ft_savelistex2(t_s *s, t_listex list, char *path, int append);

#endif
