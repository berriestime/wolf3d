#include "wolf3d.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	validate_const(void)
{
	check_error(H > W, ERR_INV_H);
	check_error(H < 300 || W < 384, ERR_INV_RES);
	check_error_inv_n(H > H_MAX, ERR_H_MAX, H_MAX);
	check_error_inv_n(W > W_MAX, ERR_W_MAX, W_MAX);
}

int	main(int argc, char **argv)
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
	check_error(argc != 2, ERR_USAGE);
	check_error(SDL_Init(SDL_INIT_EVERYTHING) != 0, SDL_GetError());
	check_error(TTF_Init() != 0, SDL_GetError());
	init_map(&wolf, argv[1]);
	init_player(wolf.player, wolf.map);
	init_bonus(&wolf);
	music(wolf.bon);
	init_tex_arr(&wolf);
	wolf_loop(&wolf);
	return (0);
}
