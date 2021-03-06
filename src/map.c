#include "wolf3d.h"

static char	*get_map(int *was_read, char *map_name)
{
	char	*s;
	int		fd;

	s = ft_strnew(MAP_MAX_SIZE + 1);
	fd = open(map_name, O_RDONLY);
	check_error(fd < 0, ERR_FILE_OPEN);
	check_error(read(fd, s, 0) < 0, ERR_FILE_READ);
	*was_read = read(fd, s, MAP_MAX_SIZE + 1);
	if (*was_read > MAP_MAX_SIZE)
		error(ERR_MAP_BIG);
	if (*was_read < MAP_MIN_SIZE)
		error(ERR_MAP_SMALL);
	return (s);
}

static void	validate_map(t_wolf *wolf, char *map, int map_size)
{
	int		first;
	int		curr_start;
	int		i;

	i = 0;
	first = -1;
	wolf->map->h = 0;
	while (i < map_size)
	{
		curr_start = i;
		while (map[i] && map[i] != '\n')
		{
			if (!ft_strchr(CHARSET, map[i]))
				error_inv_c(ERR_MAP_CHAR, map[i]);
			i++;
		}
		check_error_inv_n(i - curr_start < MAP_MIN_COL_NUM,
			ERR_MAP_COL_NUM, wolf->map->h + 1);
		first = (first == -1) * (i - curr_start) + (first != -1) * first;
		check_error(first != i - curr_start, ERR_MAP_NOT_RECT);
		i++;
		wolf->map->h++;
	}
	check_error(wolf->map->h < MAP_MIN_ROW_NUM, ERR_MAP_ROW_NUM);
	wolf->map->w = first;
}

static void	check_logic(t_wolf *wolf)
{
	int		i;
	char	*s;
	t_map	*map;

	map = wolf->map;
	i = -1;
	s = NULL;
	while (++i < map->w)
	{
		if (!ft_strchr(WALLSET, map->map[i]) || \
			!ft_strchr(WALLSET, map->map[map->w * (map->h - 1) + i]))
			error_inv_n(ERR_MAP_BORDER_COL, i + 1);
	}
	i = -1;
	while (++i < map->h)
	{
		if (!ft_strchr(WALLSET, map->map[i * map->w])
			|| !ft_strchr(WALLSET, map->map[i * map->w + (map->w - 1)]))
			error_inv_n(ERR_MAP_BORDER_ROW, i + 1);
	}
}

static void	check_start(t_wolf *wolf)
{
	int		start_coin_counter[2];
	int		i;
	t_map	*map;

	map = wolf->map;
	start_coin_counter[0] = 0;
	start_coin_counter[1] = 0;
	i = -1;
	while (++i < map->w * map->h)
	{
		if (map->map[i] == TEX_COIN)
		{
			wolf->bon->coint_pos.y = ((i / wolf->map->w) + 0.5) * CUBE;
			wolf->bon->coint_pos.x = ((i % wolf->map->w) + 0.5) * CUBE;
			map->map[i] = TEX_FLOOR;
			check_error(++start_coin_counter[1] > 1, ERR_MAP_MULT_COIN);
		}
		if (map->map[i] == TEX_START)
		{
			map->player_start = i;
			map->map[i] = TEX_FLOOR;
			check_error(++start_coin_counter[0] > 1, ERR_MAP_MULT_START);
		}
	}
	check_error(!start_coin_counter[0], ERR_MAP_NO_START);
}

void	init_map(t_wolf *wolf, char *map_name)
{
	int		map_size;
	char	*str_map;
	int		i;
	int		j;

	if (ft_strcmp((char *)(map_name + ft_strlen(map_name) - 4), ".txt"))
		error(ERR_MAP_NOT_TXT);
	str_map = get_map(&map_size, map_name);
	validate_map(wolf, str_map, map_size);
	wolf->map->map = ft_strnew(wolf->map->h * wolf->map->w);
	check_error(!wolf->map->map, ERR_MALLOC);
	i = -1;
	j = 0;
	while (++i < map_size)
		if (str_map[i] != '\n')
			wolf->map->map[j++] = str_map[i];
	wolf->map->w_pix = wolf->map->w * CUBE;
	wolf->map->h_pix = wolf->map->h * CUBE;
	free(str_map);
	check_start(wolf);
	check_logic(wolf);
	init_mm(wolf->map);
}
