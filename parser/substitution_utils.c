/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:48:53 by advorace          #+#    #+#             */
/*   Updated: 2026/05/21 17:55:35 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
