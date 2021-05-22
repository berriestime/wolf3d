/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:45:50 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:46:29 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uimaxlen(uintmax_t n)
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
