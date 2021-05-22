/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:41:55 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:43:13 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	i = 0;
	while (i < num && *p1 == *p2)
	{
		i++;
		p1++;
		p2++;
	}
	if (i == num)
		return (0);
	else
		return (*p1 - *p2);
	return (0);
}
