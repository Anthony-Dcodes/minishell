/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:29:28 by advorace          #+#    #+#             */
/*   Updated: 2026/03/20 12:33:22 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_quotes_syntax(t_token **head)
{
	int		ret;
	t_token *temp;
	int		quote_type;

	temp = *head;
	ret = ERR_OK;
	while (temp)
	{
		quote_type = temp->quote;
		if (quote_type == SINGLE_QUOTE || quote_type == DOUBLE_QUOTE)
		{
			ret = compare_first_last_char(temp->value);
			if (ret != ERR_OK)
				return (ERR_SYNTAX);
			ret = check_inner_quotes(temp->value, 1, (int)ft_strlen(temp->value) - 1);
			if (ret != ERR_OK)
				return (ERR_SYNTAX);
		}
		if (quote_type == NO_QUOTE)
			ret = check_inner_quotes(temp->value, 0, (int)ft_strlen(temp->value));
		if (ret != ERR_OK)
			return (ret);
		temp = temp->next;
	}
	return (ret);
}

int	compare_first_last_char(char *string)
{
	int	len;
	int	last_index;
	int	first_index;

	len = (int)ft_strlen(string);
	last_index = len - 1;
	first_index = 0;
	if (string[first_index] == string[last_index])
		return (0);
	return (1);
}

int	check_inner_quotes(char *string, int start_index, int end_index)
{
	int	n_single_q;
	int	n_double_q;
	int	i;

	i = start_index;
	n_single_q = 0;
	n_double_q = 0;
	if (start_index == end_index)
		return (ERR_OK);
	while (i < end_index)
	{
		if (string[i] == '\'')
			++n_single_q;
		else if (string[i] == '"')
			++n_double_q;
		++i;
	}
	if (n_single_q % 2 == 1 || n_double_q % 2 == 1)
		return (ERR_SYNTAX);
	return (ERR_OK);
}
