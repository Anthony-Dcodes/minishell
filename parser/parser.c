/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:11:29 by advorace          #+#    #+#             */
/*   Updated: 2026/03/17 21:53:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

// int ft_parsecmd(t_s *s, char *src, t_listex **dst, char **envp)
// {
// 	t_token	**head;
// 	int			ret;

// 	ret = ERR_OK;
// 	*head = NULL;
// 	ret = lexer(head, src);
// 	while (*head)
// 	{
// 		printf("word:\n", *head->value)
// 	}
// }

int main(void)
{
	t_token **head;
	int	ret;
	char	*string = "Helllo jak se mame? | ,okok se mame | done!";

	ret = lexer(head, string);
	while (*head)
	{
		printf("%s\n", *head->value);
		*head = *head->next;
	}
	return (0);
}
