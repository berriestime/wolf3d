/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:41:28 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:44:40 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free(char *format, ...)
{
	int		n;
	char	*s;
	va_list	ap;

	va_start(ap, format);
	n = ft_atoi((const char *)format);
	while (n-- > 0)
	{
		s = va_arg(ap, char *);
		free((void *)s);
	}
	va_end(ap);
	return (1);
}
