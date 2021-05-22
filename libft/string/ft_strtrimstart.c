/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimstart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:40:44 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:40:45 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimstart(char const *s, char *charset)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && ft_strchr(charset, s[i]))
		++i;
	str = ft_strdup(s + i);
	free((void *)s);
	return (str);
}
