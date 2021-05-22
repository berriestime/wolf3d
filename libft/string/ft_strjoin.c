/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:37:04 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:37:05 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup((char *)s2));
	else if (!s2)
		return (ft_strdup((char *)s1));
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	str = ft_strnew(len1 + len2);
	if (str)
	{
		ft_memcpy(str, s1, len1);
		ft_memcpy(str + len1, s2, len2 + 1);
	}
	return (str);
}
