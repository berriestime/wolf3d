/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:32:33 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 20:33:12 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	Uint32	*target_pixel;

	target_pixel = (Uint32 *)((Uint8 *)surface->pixels + y \
	* surface->pitch + x * sizeof(*target_pixel));
	*target_pixel = pixel;
}

Uint32	get_pixel(SDL_Surface *surface, int x, int y)
{
	Uint8	*p;

	p = (Uint8 *)surface->pixels + y * surface->pitch + x \
	* surface->format->BytesPerPixel;
	return (*(Uint32 *)p);
}

int	is_texture(t_map *map, int x, int y, char texture)
{
	return (map->map[(y / CUBE) *map->w + (x / CUBE)] == texture);
}
