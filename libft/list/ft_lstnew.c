/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:51:17 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:51:45 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*listnew;

	if (content_size + 1 < content_size)
		return (NULL);
	listnew = (t_list *)ft_memalloc(sizeof(t_list));
	if (!listnew)
		return (NULL);
	if (content == NULL)
	{
		listnew->content = NULL;
		listnew->content_size = 0;
	}
	else
	{
		listnew->content = malloc(content_size);
		if (listnew->content == NULL)
		{
			free(listnew);
			return (NULL);
		}
		ft_memmove(listnew->content, content, content_size);
		listnew->content_size = content_size;
	}
	listnew->next = NULL;
	return (listnew);
}
