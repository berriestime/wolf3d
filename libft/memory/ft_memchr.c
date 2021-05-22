/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:41:49 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:43:08 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *)arr;
	while (i < n)
	{
		if ((char)s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}
