/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:45:40 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:46:34 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_imaxval(char *format, ...)
{
	int		n;
	int		i;
	int		max;
	int		arg;
	va_list	ap;

	va_start(ap, format);
	n = ft_ctoi(format[0]);
	i = 0;
	max = -2147483648;
	while (i < n)
	{
		arg = va_arg(ap, int);
		max = arg > max ? arg : max;
		i++;
	}
	va_end(ap);
	return (max);
}
