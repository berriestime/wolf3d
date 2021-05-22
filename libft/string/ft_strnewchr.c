/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:39:02 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:39:03 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewchr(int size, char c)
{
	char	*buf;
	int		i;

	buf = NULL;
	if (size > 0)
	{
		buf = malloc(size + 1);
		if (!buf)
			return (NULL);
		i = 0;
		while (i < size)
			buf[i++] = c;
		buf[i] = '\0';
	}
	return (buf);
}
