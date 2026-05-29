/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:13:36 by advorace          #+#    #+#             */
/*   Updated: 2026/05/29 08:47:41 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

// String utils
size_t	ad_strlen(const char *s);
int		ad_isspace(char c);
int		ad_isalnum(int c);
int		get_string(int start, int end, char *src, char **dst);
void	*ad_memmove(void *dst, const void *src, size_t len);

//2
char	*ad_strdup(const char *s);
char	*ad_strjoin(char const *s1, char const *s2);
void	*ad_calloc(size_t nmemb, size_t size);
