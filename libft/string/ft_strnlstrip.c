/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlstrip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:39:18 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:39:19 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnlstrip(char const *s, char *charset, int n)
{
	int		first;
	char	*lstripped;

	if (s)
	{
		first = 0;
		while (n-- > 0 && s[first] && ft_strchr(charset, s[first]))
			++first;
		lstripped = ft_strdup(s + first);
		free((void *)s);
		return (lstripped);
	}
	return (NULL);
}
