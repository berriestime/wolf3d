/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:03:32 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 20:17:56 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	get_fps_time(t_bonus *bon)
{
	if (!bon->fps)
		return (1);
	if (!bon->start_time)
		bon->start_time = SDL_GetTicks();
	if (bon->start_time + 1000 < SDL_GetTicks())
	{
		bon->start_time = SDL_GetTicks();
		bon->fps = bon->fps_count;
		bon->fps_count = 0;
	}
	return (0);
}

void	render_text(t_wolf *wolf, char *text, SDL_Rect location,
			SDL_Color f_b_color[2])
{
	SDL_Surface		*txt_sur;

	txt_sur = TTF_RenderText_Shaded(wolf->bon->my_font, text, \
	f_b_color[TEXT_FOREGROUND_COLOR], f_b_color[TEXT_BACKGROUND_COLOR]);
	free(text);
	if (txt_sur == NULL)
		error(SDL_GetError());
	SDL_BlitSurface(txt_sur, NULL, wolf->surface, &location);
	SDL_FreeSurface(txt_sur);
}

void	render_fps(t_wolf *wolf, t_bonus *bon)
{
	SDL_Color		f_b_color[2];
	SDL_Surface		*txt_sur;
	char			*str1;
	char			*str2;

	if (get_fps_time(bon))
		return ;
	f_b_color[TEXT_FOREGROUND_COLOR] = set_color_sdl(255, 0, 0);
	f_b_color[TEXT_BACKGROUND_COLOR] = set_color_sdl(0, 0, 255);
	txt_sur = NULL;
	bon->fps_count++;
	str1 = ft_itoa(bon->fps);
	str2 = ft_strjoin("FPS: ", str1);
	free(str1);
	render_text(wolf, str2, \
		set_rect_sdl(W - (int)(H / 10) *2, 2, 0, 0), f_b_color);
}

void	render_score_coin(t_wolf *wolf)
{
	SDL_Color		f_b_color[2];
	SDL_Surface		*text_surface;
	char			*str;
	char			*str_tmp;

	f_b_color[TEXT_FOREGROUND_COLOR] = set_color_sdl(255, 0, 0);
	f_b_color[TEXT_BACKGROUND_COLOR] = set_color_sdl(0, 0, 255);
	text_surface = NULL;
	str_tmp = ft_itoa(wolf->bon->score_coin);
	str = ft_strjoin("score coin: ", str_tmp);
	render_text(wolf, str, \
	set_rect_sdl(W - (int)(H / 28) *9, H - (int)(H / 28), 0, 0), f_b_color);
	free(str_tmp);
}
