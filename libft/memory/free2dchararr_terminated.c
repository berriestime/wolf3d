/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2dchararr_terminated.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:41:17 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:43:53 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_2dchararr_terminated(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr[i]);
	free(arr);
	return (1);
}
