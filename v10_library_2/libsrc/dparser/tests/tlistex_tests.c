/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlistex_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:16:03 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 18:34:35 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tlistex_tests.h"
#include "../tokenizer.h"
#include "../macros.h"
#include "../structs.h"
#include "../parser.h"
#include "../convert_to_tlistx.h"

int main(void)
{
	int			i;
	t_token 	*head;
	int			ret;
	char		*str;
	t_listex	**listex;
	int		x;
	int		y;

	i = 0;
	ret = ERR_OK;
	while(tlistex_tests[i].input)
	{
		str = tlistex_tests[i].input;
		ret = parser(&head, str);
		if (ret != ERR_OK)
		{
			printf("Parser error: %d, on %s\n", ret, str);
			return (ret);
		}
		ret = fill_tlistx(head, &listex);
		if (ret != ERR_OK)
		{
			printf("fill_tlistx error: %d, on %s\n", ret, str);
			return (ret);
		}
		x = 0;
		printf("%d.Test: \"%s\"\n", i, tlistex_tests[i].input);
		printf("------------------------\n");
		while (listex[x])
		{
			y = 0;
			printf("listx[%d]\n", x);
			while (y < (int)listex[x]->size)
			{
				printf("	items[%d]: %30s, quotes int/char: [%d/%c]\n", y, listex[x]->items[y], listex[x]->xattr_qc[y], listex[x]->xattr_qc[y]);
				++y;
			}
			printf("	listx size: %zu\n", listex[x]->size);
			++x;
		}
		printf("------------------------\n\n");
		++i;
	}
	return (ERR_OK);
}
