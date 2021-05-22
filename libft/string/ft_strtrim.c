/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:40:32 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:40:33 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;
	int		end;

	if (!s)
		return (NULL);
	if (!*s)
		return ((char *)s);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	end = ft_strlen((char *)s) - 1;
	while (end > i && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	str = ft_strnew((size_t)(end - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (!(i > end))
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
