/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:37:58 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:37:59 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *app, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (j < n && app[j])
		dest[i++] = app[j++];
	dest[i] = '\0';
	return (dest);
}
