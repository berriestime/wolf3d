/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:39:42 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:39:43 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*p;

	p = NULL;
	while (*str)
	{
		if (*str == ch)
			p = (char *)str;
		str++;
	}
	if (p)
		return (p);
	if (!ch)
		return ((char *)str);
	return (NULL);
}
