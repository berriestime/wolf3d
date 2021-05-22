/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2dchararr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:41:33 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:43:55 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free2dchararr(char **arr, int rows)
{
	int		i;

	i = 0;
	while (i < rows)
		free(arr[i++]);
	free(arr);
	return (1);
}
