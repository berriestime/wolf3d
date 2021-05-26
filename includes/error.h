#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "const.h"

void	error(const char *s);
void	error_free_s(char *s);
void	error_inv_c(char *s, char inv_char);
void	error_inv_n(char *s, int inv_num);
void	check_error(_Bool status, const char *s);
void	check_error_inv_n(_Bool status, char *s, int inv_num);

#endif
