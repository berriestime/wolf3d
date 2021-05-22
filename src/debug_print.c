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
		ft_printf("%s MAP INFO %s\n", C_YEL, C_NRM);
		ft_printf("\t%d map.w | %d map.h\n", map->w, map->h);
	}
}

void	debug_player(t_player *p)
{
	if (DEBUG)
	{
		ft_printf("%s PLAYER INFO %s\n", C_GRN, C_NRM);
		ft_printf("\t%f p.x | %f p.y\n", p->x, p->y);
		ft_printf("\t%f p.dir  |  %f p.fov\n", p->dir, p->fov);
	}
}
