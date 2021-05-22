/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guns_shot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:36:05 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 20:40:44 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	check_SDL_BlitScaled(bool status, void **ptrs)
{
	if (!status)
		return ;
	SDL_BlitScaled(ptrs[0], ptrs[1], ptrs[2], ptrs[3]);
}

void	guns_shot(SDL_Surface *screen, int flag, t_bonus *bon)
{
	if (flag == 2)
	{
		Mix_Volume(0, 32);
		Mix_PlayChannel(1, bon->music_guns, 0);
		Mix_VolumeMusic(5);
	}
	check_SDL_BlitScaled(flag == 1, (void *[4]){bon->image_1, NULL, screen, \
	&bon->img_location});
	check_SDL_BlitScaled(flag == 2, (void *[4]){bon->image_2, NULL, screen, \
	&bon->img_location});
	check_SDL_BlitScaled(flag == 3, (void *[4]){bon->image_3, NULL, screen, \
	&bon->img_location});
	check_SDL_BlitScaled(flag == 4, (void *[4]){bon->image_4, NULL, screen, \
	&bon->img_location});
	check_SDL_BlitScaled(flag == 5, (void *[4]){bon->image_5, NULL, screen, \
	&bon->img_location});
}

void	render_shot(t_wolf *wolf, SDL_Surface *surface)
{
	if (wolf->bon->guns_fire || wolf->bon->flag_guns != 0)
	{
		wolf->bon->guns_fire = 0;
		if (!wolf->bon->start_guns)
		{
			wolf->bon->flag_guns++;
			wolf->bon->start_guns = SDL_GetTicks();
		}
		if (wolf->bon->start_guns + 200 < SDL_GetTicks())
		{
			wolf->bon->flag_guns++;
			wolf->bon->start_guns = SDL_GetTicks();
		}
		guns_shot(surface, wolf->bon->flag_guns, wolf->bon);
		wolf->bon->flag_guns == 5 ? wolf->bon->flag_guns = 0 : 0;
	}
	else
		guns_shot(surface, 1, wolf->bon);
}
