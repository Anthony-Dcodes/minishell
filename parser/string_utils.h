/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:13:36 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 11:05:57 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

// String utils
size_t	ft_strlen(const char *s);
int		ft_isspace(char c);
int		ft_isalnum(int c);
int		get_string(int start, int end, char *src, char **dst);
void	*ft_memmove(void *dst, const void *src, size_t len);

//2
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
