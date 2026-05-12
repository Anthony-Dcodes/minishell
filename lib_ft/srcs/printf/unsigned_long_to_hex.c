/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_long_to_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:52:17 by advorace          #+#    #+#             */
/*   Updated: 2025/07/21 17:45:06 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*reverse_string(char *str)
{
	char	temp;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		++i;
	}
	return (str);
}

char	*unsigned_long_to_hex(void *prt)
{
	char			*hex_map;
	char			*result;
	int				i;
	unsigned long	n;

	n = (unsigned long)prt;
	if (n == 0)
		return (ft_strdup("(nil)"));
	hex_map = "0123456789abcdef";
	result = ft_calloc(19, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		result[i] = hex_map[n % 16];
		n /= 16;
		++i;
	}
	result[i++] = 'x';
	result[i++] = '0';
	result[i] = '\0';
	reverse_string(result);
	return (result);
}
