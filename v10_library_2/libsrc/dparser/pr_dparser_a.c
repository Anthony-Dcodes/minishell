/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dparser_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:16 by omayer            #+#    #+#             */
/*   Updated: 2026/03/19 10:38:02 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pr_dparser.h"

void	*ft_ewmem(size_t size)
{
	return (malloc(size));
}

int	ft_efreemem(void *ptr)
{
	if (ptr)
		free(ptr);
	return (SUCCESS);
}

int	ft_ememset(void *src, int c, size_t n)
{
	char	*pc;
	size_t	i;

	i = 0;
	if ((src == NULL) || (n == 0))
		return (ENULL);
	pc = (char *)src;
	c = c % 256;
	while (i < n)
		pc[i++] = c;
	return (SUCCESS);
}

size_t	ft_estrlen2(const char *src)
{
	size_t	n;

	if (src == NULL)
		return (ENULL);
	n = 0;
	if (src)
		while (src[n])
			n++;
	return (n);
}

int	ft_estrdup2(char **r, const char *src)
{
	size_t		i;
	size_t		strlen;
	char		*result;

	if (src == NULL)
		return (ENULL);
	i = 0;
	strlen = ft_estrlen2(src);
	result = ft_ewmem(sizeof(char) * (strlen + 1));
	if (result == NULL)
		return (ENULL);
	if ((result != NULL) && (src[0] != -1))
	{
		while (i < strlen)
		{
			result[i] = src[i];
			i++;
		}
		result[i] = '\0';
	}
	*r = result;
	return (SUCCESS);
}
