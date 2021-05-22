/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:35:58 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:35:59 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrset(const char *str, const char *charset)
{
	int		i;
	char	*s;

	i = 0;
	while (charset[i])
	{
		s = ft_strchr(str, (int)charset[i]);
		if (s)
			return (s);
		i++;
	}
	return (NULL);
}
