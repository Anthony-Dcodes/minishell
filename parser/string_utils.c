/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:44:07 by advorace          #+#    #+#             */
/*   Updated: 2026/03/23 22:34:01 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	get_string(int start, int end, char *src, char **dst)
{
	int	len;
	int i;

	len = end - start;
	i = 0;
	*dst = malloc(sizeof(char) * (len + 1));
	if (!*dst)
		return (ERR_MALLOC);
	while (i < len)
	{
		(*dst)[i] = src[start + i];
		++i;
	}
	(*dst)[i] = 0;
	return (ERR_OK);
}

// Return 1 if c is alphanumeric (letter or digit)
int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
