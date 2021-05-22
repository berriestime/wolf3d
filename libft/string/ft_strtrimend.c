/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:40:38 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:40:39 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimend(char const *s, char *charset)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (i >= 0 && ft_strchr(charset, s[i]))
		i--;
	str = ft_strndup(s, i + 1);
	free((void *)s);
	return (str);
}
