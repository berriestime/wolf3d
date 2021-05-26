#include "error.h"

void	error(const char *s)
{
	ft_putstr_fd(C_RED, STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putendl_fd(C_NRM, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	error_inv_c(char *s, char inv_char)
{
	ft_putstr_fd(C_RED, STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putchar_fd(inv_char, STDERR_FILENO);
	ft_putendl_fd(C_NRM, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	error_inv_n(char *s, int inv_num)
{
	ft_putstr_fd(C_RED, STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putnbr_fd(inv_num, STDERR_FILENO);
	ft_putendl_fd(C_NRM, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
