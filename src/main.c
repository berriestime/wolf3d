#include "wolf3d.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	validate_const(void)
{
	check_error(H > W, NULL, ERR_INV_H);
	check_error(H < 300 || W < 384, NULL, ERR_INV_RES);
	check_error_inv_n(H > H_MAX, NULL, ERR_H_MAX, H_MAX);
	check_error_inv_n(W > W_MAX, NULL, ERR_W_MAX, W_MAX);
}

int	main(int a, char **b)
{
	t_wolf		wolf;
	t_map		map;
	t_player	player;
	t_sdl		sdl;
	t_bonus		bonus;

	wolf.map = &map;
	wolf.player = &player;
	wolf.sdl = &sdl;
	wolf.bon = &bonus;
	validate_const();
	check_error(a != 2, NULL, ERR_USAGE);
	check_error(SDL_Init(SDL_INIT_EVERYTHING) != 0, NULL, SDL_GetError());
	check_error(TTF_Init() != 0, NULL, SDL_GetError());
	init_map(&wolf, b[1]);
	init_player(&wolf, wolf.player, wolf.map);
	init_bonus(&wolf);
	music(wolf.bon);
	init_tex_arr(&wolf);
	wolf_loop(&wolf);
	return (0);
}
