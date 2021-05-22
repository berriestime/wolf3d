/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_horiz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:47:03 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 20:48:50 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_horiz(t_player *p, t_float2 *a,
t_float2 *diff, float angle)
{
	a->y = floorf((float)p->y / CUBE) * CUBE;
	a->y = a->y + (angle > RAD_0 && angle < RAD_180) * CUBE;
	a->x = p->x + (p->y - a->y) / tanf(angle);
	diff->x = CUBE / tanf(angle);
	if (angle > RAD_270 && angle < RAD_360)
	{
		diff->x = -diff->x;
		diff->y = CUBE;
	}
	else if (angle > RAD_90 && angle < RAD_180)
	{
		diff->x = diff->x;
		diff->y = -CUBE;
	}
	else if (angle > RAD_0 && angle < RAD_90)
	{
		diff->x = (diff->x);
		diff->y = -CUBE;
	}
	else
	{
		diff->x = -diff->x;
		diff->y = CUBE;
	}
}

static char	decide_sides_maybe_s(bool sides_mode, t_wolf *wolf, t_float2 *a)
{
	size_t	offset;

	if (sides_mode)
		return ('s');
	offset = ((int)(a->y - 1) / CUBE) * wolf->map->w + ((int)a->x / CUBE);
	return (wolf->map->map[offset]);
}

static char	decide_sides_maybe_n(bool sides_mode, t_wolf *wolf, t_float2 *a)
{
	size_t	offset;

	if (sides_mode)
		return ('n');
	offset = ((int)a->y / CUBE) * wolf->map->w + ((int)a->x / CUBE);
	return (wolf->map->map[offset]);
}

static int	calc_horiz(t_wolf *wolf, t_float2 *a,
t_distance *dist, float angle)
{
	if (angle > RAD_0 && angle < RAD_180 && \
	ft_strchr(WALLSET, wolf->map->map[((int)(a->y - 1) / CUBE) \
	*wolf->map->w + ((int)a->x / CUBE)]))
	{
		dist->dist = fabsf((wolf->player->y - a->y) / sinf(angle));
		dist->offsetx = (int)a->x % CUBE;
		dist->tex = decide_sides_maybe_s(wolf->sdl->sides_mode, wolf, a);
		return (1);
	}
	else if (ft_strchr(WALLSET, wolf->map->map[((int)a->y / CUBE) \
	*wolf->map->w + ((int)a->x / CUBE)]))
	{
		dist->dist = fabsf((wolf->player->y - a->y) / sinf(angle));
		dist->offsetx = (int)a->x % CUBE;
		dist->tex = decide_sides_maybe_n(wolf->sdl->sides_mode, wolf, a);
		return (1);
	}
	return (0);
}

t_distance	*find_horizontal_intersection(t_wolf *wolf,
	float angle, t_distance *dist)
{
	t_float2	a;
	t_float2	diff;

	init_horiz(wolf->player, &a, &diff, angle);
	while (a.y > -1 && a.y < wolf->map->h_pix && \
	a.x > -1 && a.x < wolf->map->w_pix)
	{
		if (calc_horiz(wolf, &a, dist, angle))
			break ;
		a.x += diff.x;
		a.y += diff.y;
	}
	dist->coords = a;
	return (dist);
}
