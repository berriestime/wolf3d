/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:38:22 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:38:23 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	while ((*s1 || *s2) && *s1 == *s2 && n > 1)
	{
		n--;
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (1);
	else
		return (0);
}
