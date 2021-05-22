/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtmaxlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:45:56 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:46:25 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uimaxtmaxlen(uintmax_t n)
{
	size_t	length;

	length = 0;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}
