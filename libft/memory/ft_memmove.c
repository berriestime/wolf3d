/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:42:11 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:43:25 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	if (s < d)
	{
		while (i++ < n)
			d[n - i] = s[n - i];
	}
	else
	{
		while (i++ < n)
			d[i - 1] = s[i - 1];
	}
	return (d);
}
