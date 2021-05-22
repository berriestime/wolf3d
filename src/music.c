/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:24:34 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 20:24:35 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	music(t_bonus *bon)
{
	Mix_Volume(0, 32);
	if (bon->music_flag == 1)
		Mix_PlayMusic(bon->music, -1);
	Mix_VolumeMusic(5);
}
