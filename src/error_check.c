#include "wolf3d.h"

int	check_error(bool status, t_wolf *wolf, const char *s)
{
	if (!status)
		return (0);
	return (error(wolf, s));
}

int	check_error_free_s(bool status, t_wolf *wolf, char *s)
{
	if (!status)
		return (0);
	return (error_free_s(wolf, s));
}

int	check_error_inv_n(bool status, t_wolf *wolf, char *s, int inv_num)
{
	if (!status)
		return (0);
	return (error_inv_n(wolf, s, inv_num));
}
