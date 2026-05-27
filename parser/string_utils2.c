/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:56:35 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 11:05:41 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string_utils.h"

// Retrun a pointer to new string which is duplicate of s
// If malloc fails return NULL
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		len;

	len = (int)ft_strlen(s);
	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// Allocate mem, join s1, s2
// Return resulting string or NULL
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_mem;
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	if (size != 0 && (size_t)-1 / size < nmemb)
		return (NULL);
	total_mem = nmemb * size;
	if (total_mem == 0)
		return (malloc(0));
	ptr = malloc(total_mem);
	if (ptr == NULL)
		return (NULL);
	while (i < total_mem)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
