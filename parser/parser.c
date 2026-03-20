/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:11:29 by advorace          #+#    #+#             */
/*   Updated: 2026/03/20 23:32:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

//int ft_parsecmd(t_s *s, char *src, t_listex **dst, char **envp)
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

int main(int argc, char *argv[], char **envp)
{
	t_token *head;
	t_token *current;
	int	ret;
	char	*string = "'first''second'\"third\"";

	//while (*envp)
	//{
	//	printf("env variables: %s\n", *envp);
	//	envp++;
	//}
	head = NULL;
	ret = lexer(&head, argv[1]);
	if (ret != ERR_OK)
		return (ret);
	current = head;
	while (current)
	{
		printf("%s\n", current->value);
		current = current->next;
	}
	return (ret);
}
