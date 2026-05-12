/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diu_formats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:50:42 by advorace          #+#    #+#             */
/*   Updated: 2025/07/21 17:50:07 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_diu_formats(char format_specifier, va_list *args)
{
	int				num_d;
	unsigned int	num_u;
	char			*str;

	if (format_specifier == 'd' || format_specifier == 'i')
	{
		num_d = va_arg(*args, int);
		str = ft_itoa(num_d);
		return (common_print(str));
	}
	else if (format_specifier == 'u')
	{
		num_u = va_arg(*args, unsigned int);
		str = uiota(num_u);
		return (common_print(str));
	}
	return (-1);
}
