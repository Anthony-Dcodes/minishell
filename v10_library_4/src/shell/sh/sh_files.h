/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_files.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/02/27 16:06:42 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_FILES_H
# define SH_FILES_H

# include "../../../mshell.h"
# include <fcntl.h>

int		ft_canread(t_s *s, char *path);
int		ft_canwrite(t_s *s, char *path);
int		ft_loadconfigfs2(t_s *s, t_listex *env, t_listex *envp);
int		ft_unloadconfig2(t_s *s, t_listex env);
int		ft_saveconfig2(t_s *s, t_listex *env, char **fs);

#endif