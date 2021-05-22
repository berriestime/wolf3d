#include "wolf3d.h"

int	check_draw_minimap(bool status, t_wolf *wolf, t_map *map, t_player *p)
{
	if (!status)
		return (0);
	return (draw_minimap(wolf, map, p));
}
