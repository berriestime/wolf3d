/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrvar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:36:03 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:36:04 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrvar(const char *str, char *format, ...)
{
	va_list	ap;
	int		n;
	int		c;
	char	*s;

	s = NULL;
	va_start(ap, format);
	n = ft_atoi((const char *)format);
	while (n-- > 0)
	{
		c = va_arg(ap, int);
		s = ft_strchr(str, c);
		if (s)
			return (s);
	}
	va_end(ap);
	return (s);
}
