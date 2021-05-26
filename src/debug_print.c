/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:49:32 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 20:49:33 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	debug_map(t_map *map)
{
	if (DEBUG)
	{
		ft_putstr(C_YEL);
		ft_putstr(" MAP INFO ");
		ft_putendl(C_NRM);
		ft_putnbr(map->w);
		ft_putstr(" map->w | ");
		ft_putnbr(map->h);
		ft_putendl(" map->h");
	}
}

void	debug_player(t_player *p)
{
	if (DEBUG)
	{
		ft_putstr(C_GRN);
		ft_putstr(" PLAYER INFO ");
		ft_putendl(C_NRM);
		ft_putnbr(p->x * 1000);
		ft_putstr(" p->x | ");
		ft_putnbr(p->y * 1000);
		ft_putendl(" p->y");
		ft_putnbr(p->dir * 1000);
		ft_putstr(" p->dir | ");
		ft_putnbr(p->fov * 1000);
		ft_putendl(" p->fov");
	}
}
