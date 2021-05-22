/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:52:30 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:54:06 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <string.h>
# include <stdlib.h>

typedef struct s_dlist_node
{
	struct s_dlist_node	*next;
	struct s_dlist_node	*prev;
	void				*data;
	int					*data_size;
}						t_dlist_node;

typedef struct s_dlist
{
	struct s_dlist_node	*head;
	struct s_dlist_node	*tail;
	int					size;
}						t_dlist;

t_dlist_node			*t_dlist_node_new(void *data);
t_dlist_node			*t_dlist_insert_after(t_dlist *list,
							t_dlist_node *node, t_dlist_node *new);
t_dlist_node			*t_dlist_insert_before(t_dlist *list,
							t_dlist_node *node, t_dlist_node *new);
t_dlist_node			*t_dlist_push(t_dlist *list, t_dlist_node *new);
t_dlist_node			*t_dlist_append(t_dlist *list, t_dlist_node *new);
t_dlist					*t_dlist_new();
t_dlist_node			*t_dlist_pop(t_dlist *list, t_dlist_node *node);
t_dlist					*t_dlist_remove_node(t_dlist *list, t_dlist_node *node);

#endif
