#ifndef DEFINES_H
# define DEFINES_H

# include "SDL2.framework/Headers/SDL.h"
# include "SDL2_mixer.framework/Headers/SDL_mixer.h"
# include "SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "const.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char		*map;
	int			w;
	int			h;
	int			w_pix;
	int			h_pix;
	t_point		mm_start;
	int			mm_cube;
	int			mm_show;
	int			mm_w;
	int			mm_h;
	int			mm_p_size;
	float		mm_map_coef;
	float		mm_cube_coef;
	int			player_start;
}				t_map;

typedef struct s_float2
{
	float		x;
	float		y;
}				t_float2;

typedef struct s_distance
{
	float		dist;
	char		tex;
	int			offsetx;
	int			side;
	t_float2	coords;
	int			y;
}				t_distance;

typedef struct s_player
{
	float		x;
	float		y;
	float		speed;
	int			size;
	float		fov;
	float		dir;
	float		dist_to_canvas;
	float		step;
	int			floor_offset;
	t_distance	*distance[W];
	t_distance	*distance_horiz[W];
	t_distance	*distance_vert[W];
}				t_player;

typedef struct s_sdl
{
	SDL_Surface	*scrs;
	SDL_Surface	*textures;
	SDL_Surface	*sky;
	SDL_Surface	*icon;
	SDL_Window	*win;
	int			tex_arr[0xff];
	const Uint8	*state;
	int			skybox_offset;
	int			run;
	int			sides_mode;
	int			menu;
}				t_sdl;

typedef struct s_bonus
{
	int			music_flag;
	Mix_Music	*music;
	Mix_Chunk	*music_guns;
	Mix_Chunk	*music_coin;
	int			fps;
	Uint32		start_time;
	int			fps_count;
	int			guns_fire;
	SDL_Surface	*image_1;
	SDL_Surface	*image_2;
	SDL_Surface	*image_3;
	SDL_Surface	*image_4;
	SDL_Surface	*image_5;
	SDL_Surface	*image_coin;
	t_float2	coint_pos;
	int			score_coin;
	SDL_Rect	img_location;
	int			flag_guns;
	Uint32		start_guns;
	TTF_Font	*my_font;
}				t_bonus;

typedef struct s_wolf
{
	t_map		*map;
	t_player	*player;
	t_sdl		*sdl;
	SDL_Surface	*surface;
	t_bonus		*bon;
	int			error_code;
}				t_wolf;

#endif
