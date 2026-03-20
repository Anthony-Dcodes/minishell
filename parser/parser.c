/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:11:29 by advorace          #+#    #+#             */
/*   Updated: 2026/03/20 12:32:39 by advorace         ###   ########.fr       */
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
	char	*string = "echo a | echo b | cat a 'error' sec";

	//while (*envp)
	//{
	//	printf("env variables: %s\n", *envp);
	//	envp++;
	//}
	head = NULL;
	ret = lexer(&head, string);
	if (ret != ERR_OK)
		return (ret);
	current = head;
	while (current)
	{
		printf("value: |%s|, is pipe: %d, quote: %d\n", current->value, current->is_pipe, current->quote);
		current = current->next;
	}
	return (ret);
}
