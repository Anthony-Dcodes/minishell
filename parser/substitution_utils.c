/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:48:53 by advorace          #+#    #+#             */
/*   Updated: 2026/05/22 10:28:54 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	env_first_char_valid(char c)
{
	if ((c >= 'A' && c <= 'Z')
		|| c >= 'a' && c <= 'z'
		|| c == '_')
		return (1);
	return (0);
}

int env_whitelist_char(char c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9')
		|| c == '_')
		return (1);
	return (0);
}

char	*get_env_value(char *string)
{
	return (getenv(string));
}