/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:08:51 by advorace          #+#    #+#             */
/*   Updated: 2026/03/17 21:35:12 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//echo a b | echo c
int	lexer(t_token **head, char *src)
{
	int	ret;
	int	start_index;
	int	end_index;
	int	str_end;
	char	*string;
	int		quote;
	int		pipe;
	t_token *token;

	start_index = 0;
	ret = ERR_OK;
	str_end = 0;
	while (!str_end && ret == ERR_OK)
	{
		start_index = find_start_index(src, start_index);
		if (start_index == -1)
			str_end = 1;
		quote = detect_quote(src[start_index]);
		pipe = detect_pipe(src[start_index]);
		end_index = find_end_index(src, start_index, quote);
		if (end_index == -1)
			str_end = 1;
		if (end_index == -2)
			return (ERR_SYNTAX);
		ret = get_string(start_index, end_index, src, &string);
		if (ret != ERR_OK)
			return (ret);
		token = new_token(string, pipe, quote, &ret);
		if (ret != ERR_OK)
			return (ret);
		append_token(head, token);
		start_index = end_index;
	}
	return (ret);
}

int	find_start_index(char *str, int start)
{
	if (start == -1)
		return (-1);
	while (str[start])
	{
		if (str[start] == ' ')
		{
			++start;
			continue;
		}
		return (start);
	}
	return (-1);
}

int find_end_index(char *str, int start, int quote)
{
	int	end;

	end = start + 1;
	if (str[end] == 0 || start == -1)
		return (-1);
	while (str[end])
	{
		if (quote == SINGLE_QUOTE && str[end] == '\'')
				return (end);
		else if (quote == DOUBLE_QUOTE && str[end] == '"')
				return (end);
		else if (quote == NO_QUOTE && str[end] == ' ')
				return (end);
		++end;
	}
	if (quote == NO_QUOTE)
		return (-1);
	return (-2);
}

int	get_string(int start, int end, char *src, char **dst)
{
	int	ret;
	int	len;
	int i;

	ret = ERR_OK;
	len = end - start + 1;
	i = 0;
	*dst = malloc(sizeof(char) * (len + 1));
	if (!*dst)
		return (ERR_MALLOC);
	while (i < len)
	{
		(*dst)[i] = src[start + i];
		++i;
	}
	*dst[i] = 0;
	return (ret);
}

int	detect_quote(char c)
{
	if (c == SINGLE_QUOTE)
		return (SINGLE_QUOTE);
	else if (c == DOUBLE_QUOTE)
		return (DOUBLE_QUOTE);
	else if (c == NO_QUOTE)
		return (NO_QUOTE);
}

int	detect_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

t_token *new_token(char *value, int	is_pipe, int quote, int *ret)
{
	t_token *new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		ret = ERR_MALLOC;
		return ;
	}
	new_token->is_pipe = is_pipe;
	new_token->quote = quote;
	new_token->value = value;
	new_token->next = NULL;
	return (new_token);
}

void	append_token(t_token **head, t_token *new)
{
	t_token *temp_head;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	temp_head = *head;
	while (temp_head->next)
		temp_head = temp_head->next;
	temp_head->next = new;
	return ;
}
