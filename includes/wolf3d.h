#ifndef WOLF3D_H
# define WOLF3D_H

# include "SDL2.framework/Headers/SDL.h"
# include "SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "SDL2_image.framework/Headers/SDL_image.h"
# include "SDL2_mixer.framework/Headers/SDL_mixer.h"
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "defines.h"
# include "const.h"
# include "colors.h"
# include "error.h"
# include "errors.h"

typedef struct s_coin
{
	float		angle;
	float		dist;
	float		temp_1;
	float		temp_2;
	float		temp_3;
	float		temp_4;
	float		temp_5;
	int			i;
	int			flag_1;
	int			flag_2;
	int			flag_i;
	int			count;
	SDL_Rect	cut_vertical_img;
	SDL_Rect	img_location;
}				t_coin;

/*
** draw.c
*/
void			draw_background(SDL_Surface *surface);
int				check_draw_minimap(bool status,
					t_wolf *wolf, t_map *map, t_player *p);
int				draw_minimap(t_wolf *wolf, t_map *map, t_player *p);
void			draw_ray(t_wolf *wolf, float player, int x, int y);
void			draw_line(SDL_Surface *surface, t_point start, t_point end, \
int color);
void			draw_rectangle(SDL_Surface *surface, t_point start, \
t_point width_height, int color);

/*
** sdl.c
*/
void			wolf_loop(t_wolf *wolf);

/*
** main.c
*/
t_point			dot(int x, int y);
int				max(int a, int b);

/*
** move.c
*/
void			calc_move(t_map *map, t_player *p, float dy, float dx);
void			rotate(t_wolf *wolf, SDL_Event *event, int *x);
void			add_skybox_offset(t_sdl *sdl, int to_add);

/*
** load_textures.c
*/
void			set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
Uint32			get_pixel(SDL_Surface *surface, int x, int y);
int				is_texture(t_map *map, int x, int y, char texture);

/*
** debug_print.c
*/
void			debug_map(t_map *map);
void			debug_player(t_player *p);

/*
** map.c
*/
void			init_map(t_wolf *wolf, char *b);

/*
** init.c
*/
void			init_player(t_player *player, t_map *map);
void			init_sdl(t_wolf *wolf);
void			init_mm(t_map *map);
void			init_tex_arr(t_wolf *wolf);

/*
** init_bonus.c
*/
void			init_bonus(t_wolf *wolf);
void			init_bonus_load(t_wolf *wolf);

/*
** aux.c
*/
int				check_draw_menu(bool status, t_wolf *wolf);
int				draw_menu(t_wolf *wolf);
int				draw_menu_text(t_wolf *wolf, SDL_Color f_b_color[2]);
int				add_arc(float *arc, float to_add);
int				is_angle(float angle, float rad);
int				float_is_equal(float a, float b);

/*
** render_text.c
*/
void			render_text(t_wolf *wolf, char *text, SDL_Rect location, \
SDL_Color f_b_color[2]);
void			render_score_coin(t_wolf *wolf);
void			render_fps(t_wolf *wolf, t_bonus *bon);
int				get_fps_time(t_bonus *bon);

/*
** distance.c
*/
t_distance		*dist_to_wall(t_wolf *wolf, float angle, int count_distance);
t_distance		*t_distance_new();
void			t_distance_clear(t_distance *dist);
void			all_get_distance(t_wolf *wolf);
void			free_dist_arr(t_wolf *wolf);

/*
** render_coin.c
*/
void			render_coin(t_wolf *wolf, SDL_Surface *surface);
int				score_coin(t_wolf *wolf, t_coin *coin);
int				search_angle(t_wolf *wolf, t_coin *coin);
void			through_zero(t_wolf *wolf, t_coin *coin);
void			wall_check_coin(t_wolf *wolf, t_coin *coin);

/*
** set_sdl.c
*/
SDL_Color		set_color_sdl(int a, int b, int c);
SDL_Rect		set_rect_sdl(int x, int y, int w, int h);

/*
** pseudo_3d.c
*/
void			pseudo_3d(t_wolf *wolf, t_player *player, SDL_Surface *surface);
void			draw_sky(t_wolf *wolf, int x, int y);
void			draw_floor(SDL_Surface *surface, int x, int y);
void			draw_column(t_wolf *wolf, t_point point, \
t_distance *dist, int size);

/*
** distance_horiz.c
*/
t_distance		*find_horizontal_intersection(t_wolf *wolf, \
float angle, t_distance *dist);

/*
** distance_vert.c
*/
t_distance		*find_vertical_intersection(t_wolf *wolf, \
float angle, t_distance *dist);

/*
** guns_shot.c
*/
void			guns_shot(SDL_Surface *screen, int flag, t_bonus *bon);
void			render_shot(t_wolf *wolf, SDL_Surface *surface);

/*
** music.c
*/
void			music(t_bonus *bon);

#endif
