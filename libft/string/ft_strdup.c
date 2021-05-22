/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:36:37 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:36:38 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char			*dupl;
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	dupl = (char *)malloc(sizeof(char) * (len + 1));
	if (!dupl)
		return (NULL);
	len = 0;
	while (src[len])
	{
		dupl[len] = src[len];
		len++;
	}
	dupl[len] = '\0';
	return (dupl);
}
