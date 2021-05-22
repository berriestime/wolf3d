/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:43:39 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 20:43:48 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	check_error(bool status, t_wolf *wolf, const char *s)
{
	if (!status)
		return ;
	return (error(wolf, s));
}

int	error(t_wolf *wolf, const char *s)
{
	ft_dprintf(STDERR_FILENO, "%s%s%s\n", C_RED, s, C_NRM);
	exit(EXIT_FAILURE);
	wolf->error_code = 1;
	return (wolf->error_code);
}

int	error_free_s(t_wolf *wolf, char *s)
{
	ft_dprintf(STDERR_FILENO, "%s%s%s\n", C_RED, s, C_NRM);
	free(s);
	exit(EXIT_FAILURE);
	wolf->error_code = 1;
	return (wolf->error_code);
}

int	error_inv_c(t_wolf *wolf, char *s, char inv_char)
{
	ft_dprintf(STDERR_FILENO, "%s%s%c%s\n", C_RED, s, inv_char, C_NRM);
	exit(EXIT_FAILURE);
	wolf->error_code = 1;
	return (wolf->error_code);
}

int	check_error_inv_n(bool status, t_wolf *wolf, char *s, int inv_num)
{
	if (!status)
		return ;
	return (error_inv_n(wolf, s, inv_num));
}

int	error_inv_n(t_wolf *wolf, char *s, int inv_num)
{
	ft_dprintf(STDERR_FILENO, "%s%s%c%s\n", C_RED, s, inv_num, C_NRM);
	exit(EXIT_FAILURE);
	wolf->error_code = 1;
	return (wolf->error_code);
}
