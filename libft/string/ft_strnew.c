/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:38:27 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:38:28 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	if (size + 1 < size)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
