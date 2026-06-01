/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_lib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/18 17:20:43 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_LIB_H
# define L_LIB_H

# define _XOPEN_SOURCE 501

# include <string.h>
# include <stdlib.h>

int			ft_itoa2(t_s *s, char **r, int n);
int			ft_atoi2(t_s *s, int *r, const char *nptr);
int			ft_memset2(t_s *s, void *src, int c, size_t n);
void		*ft_wmem(size_t size);
void		*ft_getmem(t_s *s, size_t size);
int			ft_freemem(t_s *s, void *ptr);
int			ft_collector(void *s, int mode, void *ptr, int exitmode);
int			ft_collector_b(void *s, int mode, void *ptr, int exitmode);
size_t		ft_strlen2(t_s *s, const char *src);
int			ft_strdup2(t_s *s, char **r, const char *src);
int			ft_strdups2(t_s *s, char **r, const char *src, size_t strlen);
int			ft_strncmp2(t_s *s, const char *s1, const char *s2, size_t n);
int			ft_strrchrpos2(t_s *s, const char *src, int c);
size_t		ft_strlcpl2(t_s *s, char *dst, const char *src, size_t size);
size_t		ft_strlcpy2(t_s *s, char *dst, const char *src, size_t size);
int			ft_substr2(t_s *s, char const *src, size_t start, size_t len);
int			ft_reducestr2(t_s *s, char **dst, size_t size);
int			ft_strextract2(t_s *s, t_listex *r, char *src, char c);
int			ft_strjoin2(t_s *s, char **r, char const *s1, char const *s2);
int			ft_strtrim2(t_s *s, char **r, char const *s1, char *set);
int			ft_strchr2(t_s *s, char **r, const char *src, int c);
size_t		ft_strchrpos2(t_s *s, const char *src, int c);
size_t		ft_strrchrpose2(t_s *s, const char *src, int c);
size_t		ft_strchrpose2(t_s *s, const char *src, int c);
size_t		ft_strchrocc2(t_s *s, const char *src, int c);
int			ft_isemptyitem2(t_s *s, char *src);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_equal2(t_s *s, char *s1, char *s2, int exact);
int			ft_envequal2(t_s *s, char *envitem, char *var);
size_t		ft_countwords2(t_s *s, const char *src, char c);
int			ft_isalpha(int c);
int			ft_isnotredir(t_s *s, char *src);
size_t		ft_exchar(t_s *s, char *src, int a, int b);

#endif