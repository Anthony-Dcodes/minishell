/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_valid_env_chars.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:57:00 by advorace          #+#    #+#             */
/*   Updated: 2026/05/25 13:25:54 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	envar_first_char_valid(char c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| c == '_')
		return (1);
	return (0);
}

int	envar_char_valid(char c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9')
		|| c == '_')
		return (1);
	return (0);
}
