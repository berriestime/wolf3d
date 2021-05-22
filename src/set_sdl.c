/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sdl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:03:25 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 20:03:26 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Color	set_color_sdl(int a, int b, int c)
{
	SDL_Color	color;

	color.r = a;
	color.g = b;
	color.b = c;
	color.a = 255;
	return (color);
}

SDL_Rect	set_rect_sdl(int x, int y, int w, int h)
{
	SDL_Rect	location;

	location.w = w;
	location.h = h;
	location.x = x;
	location.y = y;
	return (location);
}
