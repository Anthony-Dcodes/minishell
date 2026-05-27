/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:11:29 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 14:12:32 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "macros.h"
#include "substitution.h"
#include "syntax_checker.h"
#include "tokenizer.h"
#include "remove_quotes.h"

int parser(t_token **head, char *input)
{
	t_token *head;
	int	ret;

	head = NULL;
	ret = tokenizer(head, input);
	if (ret != ERR_OK)
		return (ret);
	ret = syntax_checker(*head);
	if (ret != ERR_OK)
		return (ret);
	ret = substitute_vars(*head);
	if (ret != ERR_OK)
		return (ret);
	ret = remove_quotes(*head);
	if (ret != ERR_OK)
		return (ret);
	return (ret);
}
