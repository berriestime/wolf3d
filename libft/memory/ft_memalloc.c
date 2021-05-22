/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:41:38 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:42:57 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	if (size + 1 < size)
		return (NULL);
	a = malloc(size);
	if (!a)
		return (NULL);
	ft_memset(a, 0, size);
	return (a);
}
