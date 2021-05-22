/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:29:14 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 20:32:09 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point	dot(int x, int y)
{
	t_point	new;

	new.x = x;
	new.y = y;
	return (new);
}

int	max(int a, int b)
{
	return (a > b ? a : b);
}

static t_wolf	*t_wolf_new(void)
{
	t_wolf		*new;

	!(new = (t_wolf *)malloc(sizeof(t_wolf))) ? error(new, ERR_MALLOC) : 0;
	!(new->map = (t_map *)malloc(sizeof(t_map))) ? error(new, ERR_MALLOC) : 0;
	new->player = (t_player *)malloc(sizeof(t_player));
	if (!(new->player))
		error(new, ERR_MALLOC);
	new->sdl = (t_sdl *)malloc(sizeof(t_sdl));
	if (!(new->sdl))
		error(new, ERR_MALLOC);
	new->error_code = 0;
	new->bon = (t_bonus *)malloc(sizeof(t_bonus));
	if (!(new->bon))
		error(new, ERR_MALLOC);
	return (new);
}

static void	validate_const(t_wolf *wolf)
{
	H > W ? error(wolf, ERR_INV_H) : 0;
	H < 300 || W < 384 ? error(wolf, ERR_INV_RES) : 0;
	H > H_MAX ? error_inv_n(wolf, ERR_H_MAX, H_MAX) : 0;
	W > W_MAX ? error_inv_n(wolf, ERR_W_MAX, W_MAX) : 0;
}

int	main(int a, char **b)
{
	t_wolf		*wolf;

	wolf = NULL;
	validate_const(wolf);
	a != 2 ? error(wolf, ERR_USAGE) : 0;
	SDL_Init(SDL_INIT_EVERYTHING) != 0 ? error(wolf, SDL_GetError()) : 0;
	TTF_Init() != 0 ? error(wolf, SDL_GetError()) : 0;
	wolf = t_wolf_new();
	init_map(wolf, b[1]);
	init_player(wolf, wolf->player, wolf->map);
	init_bonus(wolf);
	music(wolf->bon);
	init_tex_arr(wolf);
	wolf_loop(wolf);
	return (0);
}
