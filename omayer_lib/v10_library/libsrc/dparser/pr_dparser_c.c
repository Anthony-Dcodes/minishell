/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dparser_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:16 by omayer            #+#    #+#             */
/*   Updated: 2026/03/19 10:47:55 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pr_dparser.h"

int	ft_eresetnewlist(t_listex *list, size_t words, int init)
{
	if (init)
		list->items = NULL;
	list->xattr_qc = ft_ewmem(sizeof(char *) * (words + 1));
	if (list->xattr_qc == NULL)
		return (ENULL);
	list->xattr_sc = ft_ewmem(sizeof(char *) * (words + 1));
	if (list->xattr_sc == NULL)
		return (ENULL);
	list->xattr_pc = ft_ewmem(sizeof(char *) * (words + 1));
	if (list->xattr_pc == NULL)
		return (ENULL);
	list->xattr_pidx = ft_ewmem(sizeof(char *) * (words + 1));
	if (list->xattr_pidx == NULL)
		return (ENULL);
	list->xattr_rc = ft_ewmem(sizeof(char *) * (words + 1));
	if (list->xattr_rc == NULL)
		return (ENULL);
	list->size = words;
	ft_ememset(list->xattr_pc, FALSE, words + 1);
	ft_ememset(list->xattr_pidx, FALSE, words + 1);
	ft_ememset(list->xattr_sc, FALSE, words + 1);
	ft_ememset(list->xattr_qc, FALSE, words + 1);
	ft_ememset(list->xattr_rc, FALSE, words + 1);
	return (SUCCESS);
}

int	ft_enewlistex2(t_listex *list, size_t words, int init)
{
	if (list == NULL)
		return (ENULL);
	if ((int)words == AD)
		words = list->size;
	if (words)
		ft_eresetnewlist(list, words, init);
	else
	{
		list->items = NULL;
		list->xattr_qc = NULL;
		list->xattr_sc = NULL;
		list->xattr_pc = NULL;
		list->xattr_pidx = NULL;
		list->xattr_rc = NULL;
		list->size = 0;
	}
	return (SUCCESS);
}

int	ft_elistaddex2(t_listex *list, char *src)
{
	if ((list == NULL) || (src == NULL))
		return (ENULL);
	ft_elistadd2(&list->items, list->items, src, &list->size);
	return (SUCCESS);
}

int	ft_enewlistexarr2(t_listex ***list, size_t size)
{
	size_t		i;
	t_listex	**llist;

	if (list == NULL)
		return (ENULL);
	i = 0;
	*list = NULL;
	if (size)
	{
		llist = ft_ewmem(sizeof(t_listex *) * (size + 1));
		if (llist == NULL)
			return (ENULL);
		while (i++ < size)
		{
			llist[i - 1] = ft_ewmem(sizeof(struct s_listex));
			if (llist[i - 1] == NULL)
				return (ENULL);
		}
		llist[i - 1] = NULL;
		*list = llist;
	}
	return (SUCCESS);
}
