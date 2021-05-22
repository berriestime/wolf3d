/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:51:12 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:52:00 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		lst->content = NULL;
		lst->content_size = 0;
		free(lst->next);
		lst->next = NULL;
		free(lst);
		lst = tmp;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*newlist;

	if (!f || !lst)
		return (NULL);
	newlist = (t_list *)malloc(sizeof(t_list) * 1);
	if (!newlist)
		return (NULL);
	newlist = f(lst);
	temp = newlist;
	while (lst->next)
	{
		newlist->next = (t_list *)malloc(sizeof(t_list) * 1);
		if (!newlist->next)
		{
			free_list(temp);
			return (NULL);
		}
		newlist->next = f(lst->next);
		newlist = newlist->next;
		lst = lst->next;
	}
	newlist->next = NULL;
	return (temp);
}
