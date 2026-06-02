/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dparser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/05/29 21:26:14 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PR_DPARSER_H
# define PR_DPARSER_H

# define _XOPEN_SOURCE 501

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ENULL -3
# define ERROR -1
# define AD -1

# include <string.h>
# include <stdlib.h>
# include "structs.h"

void	*ft_ewmem(size_t size);
int		ft_efreemem(void *ptr);
int		ft_ememset(void *src, int c, size_t n);
size_t	ft_estrlen2(const char *src);
int		ft_estrdup2(char **r, const char *src);

int		ft_elistadd2(char ***dstlist, char **srclist, char *src, size_t *size);
size_t	ft_elistlen2(char **src);
int		ft_elistfree2(char **src, size_t len);

int		ft_eresetnewlist(t_listex *list, size_t words, int init);
int		ft_enewlistex2(t_listex *list, size_t words, int init);
int		ft_elistaddex2(t_listex *list, char *src);
int		ft_enewlistexarr2(t_listex ***list, size_t size);

int		ft_eparsermain(t_s *s, char *src, t_listex ***dst, char **envp);

#endif