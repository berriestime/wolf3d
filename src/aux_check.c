#include "wolf3d.h"

int	check_draw_menu(bool status, t_wolf *wolf)
{
	if (!status)
		return (0);
	return (draw_menu(wolf));
}
