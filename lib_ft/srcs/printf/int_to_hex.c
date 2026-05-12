/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:33:10 by advorace          #+#    #+#             */
/*   Updated: 2025/07/10 21:14:28 by advorace         ###   ########.fr       */
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

char	*int_to_hex(int num)
{
	char			*hex_map;
	char			*result;
	int				i;
	unsigned int	n;

	n = num;
	if (n == 0)
		return (ft_strdup("0"));
	hex_map = "0123456789abcdef";
	result = ft_calloc(13, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		result[i] = hex_map[n % 16];
		n /= 16;
		++i;
	}
	result[i] = '\0';
	reverse_string(result);
	return (result);
}

// int	main(void)
// {
// 	ft_putstr_fd(int_to_hex(100), 1);
// 	ft_putendl_fd("", 1);
// 	ft_putstr_fd(int_to_hex(98), 1);
// 	ft_putendl_fd("", 1);
// 	ft_putstr_fd(int_to_hex(-88), 1);
// 	ft_putendl_fd("", 1);
// 	ft_putstr_fd(int_to_hex(0), 1);
// }
