/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:11:29 by advorace          #+#    #+#             */
/*   Updated: 2026/05/28 21:32:26 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "macros.h"
#include "substitution.h"
#include "syntax_checker.h"
#include "tokenizer.h"
#include "remove_quotes.h"
#include "convert_to_tlistx.h"

int parser(char *input, t_listex ***listex)
{
	int		ret;
	t_token **head;

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
	ret = fill_tlistx(*head, listex);
	free_tokens(head);
	return (ret);
}
