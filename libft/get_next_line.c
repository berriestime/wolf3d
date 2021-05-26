/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:30:47 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/05 19:06:07 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd_list	*create_fd_list(const int fd)
{
	t_fd_list	*ret;

	ret = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!ret)
		return ((void *)0);
	ret->fd = fd;
	ret->leftovers = ft_strnew(0);
	ft_bzero(ret->buffer, BUFF_SIZE + 1);
	ret->next = (void *)0;
	return (ret);
}

static t_fd_list	*get_entry(t_fd_list **db, const int fd)
{
	t_fd_list	*elem;

	if (fd < 0)
		return ((void *)0);
	if (!*db)
		return (*db = create_fd_list(fd));
	elem = *db;
	while (elem)
	{
		if (elem->fd == fd)
			return (elem);
		elem = elem->next;
	}
	elem = create_fd_list(fd);
	if (!elem)
		return ((void *)0);
	elem->next = *db;
	*db = elem;
	return (*db);
}

#define LDATA 0
#define LCOPY 1

static int	read_until_lf(char **data, char **ret, char *status)
{
	char	*lf_ptr;
	size_t	len[2];
	char	*tmp;

	len[LDATA] = ft_strlen(*data);
	lf_ptr = ft_strchr(*data, '\n');
	if (!lf_ptr)
		len[LCOPY] = len[LDATA];
	else
		len[LCOPY] = lf_ptr - *data;
	*ret = ft_strsub(*data, 0, len[LCOPY]);
	if (!*ret)
		return (*status = STATUS_ERR);
	if (len[LCOPY] == len[LDATA])
		tmp = ft_strnew(BUFF_SIZE);
	else
		tmp = ft_strsub(*data, len[LCOPY] + 1, len[LDATA] - len[LCOPY] - 1);
	ft_memdel((void **)data);
	*data = tmp;
	return (*status = STATUS_READ);
}

int	get_next_line(const int fd, char **line)
{
	static t_fd_list	*db;
	t_fd_list			*elem;
	ssize_t				rsize;
	char				status;

	if (!line)
		return (-1);
	elem = get_entry(&db, fd);
	if (!elem)
		return (-1);
	status = STATUS_READ;
	if (read_until_lf(&elem->leftovers, line, &status))
		return (status);
	while (1)
	{
		rsize = read(fd, elem->leftovers, BUFF_SIZE);
		if (rsize <= 0)
			break ;
		elem->leftovers[rsize] = '\0';
		if (read_until_lf(&elem->leftovers, line, &status))
			return (status);
	}
	if (ft_strlen(*line))
		return (1);
	return (rsize);
}
