/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dparser_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:16 by omayer            #+#    #+#             */
/*   Updated: 2026/03/21 05:06:38 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pr_dparser.h"

int	ft_elistadd2(char ***dstlist, char **srclist, char *src, size_t *size)
{
	size_t		i;
	size_t		len;
	char		**result;

	if (src == NULL)
		return (ENULL);
	len = 0;
	if ((srclist) && (*size))
		len = ft_elistlen2(srclist);
	result = ft_ewmem(sizeof(char *) * (len + 2));
	if (result == NULL)
		return (ENULL);
	i = 0;
	while ((len) && (i < len))
	{
		ft_estrdup2(&result[i], srclist[i]);
		i++;
	}
	ft_estrdup2(&result[i++], src);
	result[i] = NULL;
	if (len)
		ft_elistfree2(srclist, ft_elistlen2(srclist));
	*size = i;
	*dstlist = result;
	return (SUCCESS);
}

size_t	ft_elistlen2(char **src)
{
	size_t	n;

	n = 0;
	while (src[n])
		n++;
	return (n);
}

int	ft_elistfree2(char **src, size_t len)
{
	size_t		i;

	if ((int)len == AD)
		len = ft_elistlen2(src);
	i = len;
	if (src)
		while (i--)
			ft_efreemem(src[i]);
	ft_efreemem(src);
	return (SUCCESS);
}
