#include "wolf3d.h"

void	check_error(bool status, const char *s)
{
	if (!status)
		return ;
	return (error(s));
}

void	check_error_inv_n(bool status, char *s, int inv_num)
{
	if (!status)
		return ;
	return (error_inv_n(s, inv_num));
}
