/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:50:05 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/11 18:23:00 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>

# define ERROR 1
# define SUCCESS 0

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define FLOOR 0
# define CEILING 1

# define BUFFER_SIZE				1
# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3
# define ESC						65307
# define W							119
# define A							97
# define S							115
# define D							100

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_key;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_door
{
	t_vec			pos_door;
	long			wait;
	struct s_door	*next;
}	t_door;

typedef struct s_pars
{
	int				file_fd;
	char			*file_name;
	int				nb_line_of_file;
	int				nb_bigger_line;
	char			**file;
	char			**north;
	char			**south;
	char			**west;
	char			**east;
	char			*floor;
	char			*ceiling;
	char			**door;
	char			**sprite;
	struct s_data	*data;
}	t_pars;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img;
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	t_vec	screen;
	int		img_width;
	int		img_height;
}	t_mlx;

typedef struct s_sprit
{
	t_vec			pos;
	double			dist;
	struct s_sprit	*next;
}	t_sprit;

typedef struct s_data
{
	t_mlx	*mlx;
	t_mlx	*north;
	t_mlx	*south;
	t_mlx	*west;
	t_mlx	*east;
	t_mlx	*door;
	t_mlx	*sprite_img;
	t_sprit	*sprite;
	int		color_f;
	int		color_c;
	char	**map;
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	int		width;
	int		height;
	int		top;
	int		down;
	double	dist;
	int		wall;
	double	*z_buffer;
	t_pars	*pars;
	t_door	*list_door;
	long	last_move;
	t_key	*key;
}	t_data;

/*----------------get_next_line.c-----------------*/

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(char *s);
char	*get_next_line(int fd, char **line);

/*----------------get_next_line_utils.c-----------------*/

int		is_charset(char *str, char c);
char	*get_previous(char *st);
char	*get_next(char *st);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);

/*----------------parsing.c-----------------*/

int		get_nb_line(t_pars *pars);
void	check_informations(t_pars *pars, t_data *d);
void	change_map(t_pars *pars);
void	check_map(t_pars *pars, int i);
void	parsing(t_data *d, char **argv);

/*----------------parsing_init.c--------------*/

void	init_data(t_data *data);
void	init_pars(t_pars *pars, char **argv, t_data *d);

/*----------------parsing_utils.c-----------------*/

int		ft_is_space(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		cmp_str(const char *s1, const char *s2);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

/*----------------parsing_utils_bis.c-----------------*/

int		check_charset(char *color, char what);
int		ft_strncmp_parsing(const char *s1, const char *s2);
int		ft_error(char *str);
void	ft_free_close_error(char *str, t_pars *pars);
void	free_str(char **str);

/*----------------ft_split.c-----------------*/

char	**ft_split(const char *s, char c);

/*----------------ft_split_parsing.c-----------------*/

char	**ft_split_parsing(const char *s);

/*----------------parsing_check_colors.c---------------*/

int		check_charset_commas(int j, char *color);
int		check_charset_digit(int j, char *color);
int		check_color_digit(char *color, int nb_commas, int i);
int		define_color(char what, int nb, t_data *d, int multi);
void	check_colors(t_pars *pars, t_data *d, char *color, char what);

/*----------------parsing_check_textures.c-----------------*/

void	collect_textures(t_pars *pars);
void	check_array_texture(char **texture, t_pars *pars);
void	check_path_textures(t_pars *pars, t_data *d);
int		fill_mlx_ptr(t_data *d);
void	verify_textures(t_pars *pars, t_data *d);

/*----------------parsing_fill_map.c-----------------*/

char	*put_file_in_map(t_pars *pars, char **new_map, int i);
void	init_position(int i, int j, t_data *d, char **map);
int		is_charset_map(char map);
int		check_char_map(char **map, t_data *d, t_pars *pars);

/*----------------parsing_check_map.c-----------------*/

int		check_first_last_line(t_pars *pars, char **map);
int		around_map(char **map, int i, int j);
int		sides_map(char **map, int i, int j);
int		check_spaces_map(char **map);
int		verify_map(t_pars *pars);

/*----------------render.c--------------------*/

long	get_time(void);
void	open_door(t_data *data);
void	render(t_data *data);

/*----------------lst.c--------------------*/

t_door	*delete_lst(t_door *lst);
t_door	*new_cell(double x, double y, long wait);
void	add_cell(t_door **door, t_door *new);

/*----------------vector.c---------------------*/

t_vec	init_vec(double x, double y);
double	size_vec(t_vec v);
void	rotate(double angle, t_vec *v);

/*----------------vector_op.c---------------------*/

t_vec	add_vec(t_vec a, t_vec b);
t_vec	sub_vec(t_vec a, t_vec b);
t_vec	mult_dbl(t_vec v, double dbl);
double	dot(t_vec a, t_vec b);
t_vec	normalize(t_vec v);

/*----------------init_mlx.c-----------------------*/

t_mlx	*init_mlx(void);

/*----------------free.c--------------------*/

void	mlx_free_img(void *mlx_ptr, t_mlx *mlx);
void	free_sprites(t_sprit *s);
void	free_data(t_data *data);

/*----------------key_hook.c-----------------------*/

int		win_close(t_data *data, int e);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

/*----------------draw.c----------------------*/

void	draw(t_data *data);
int		is_left(t_vec pos, t_vec v, t_vec point);
int		get_color(double x, double y, t_mlx *side);

/*----------------key.c----------------------*/

int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

/*----------------draw_sprites.c----------------------*/

int		draw_sprites_angle_y(t_data *data, int x, t_vec size, t_vec start);
double	draw_sprites_angle(t_data *data, t_sprit *s, double angle);

/*----------------raycasting.c--------------------*/

int		check_hit(t_vec *map, t_vec *side, t_vec delta, t_vec dir);
double	get_dist_hit(t_data *data, t_vec v, int *wall);

/*----------------raycasting_utils.c--------------------*/

t_vec	get_delta(t_vec dir);
t_vec	get_side(t_vec pos, t_vec dir, t_vec delta);

/*----------------minimap.c----------------------*/

void	minimap(t_data *data);
int		get_color_mini(t_data *data, t_vec min, t_vec max, t_vec pix);

/*----------------mlx.c-------------------*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*----------------get_color.c-------------------*/

int		get_doors_color(t_data *data, t_vec v, int wall, double height);
int		get_wall_color(t_data *data, t_vec v, int wall, double height);

/*----------------hit.c----------------------*/

int		hit_door(t_data *data);
int		hit_up(t_data *data);
int		hit_down(t_data *data);
int		hit_left(t_data *data);
int		hit_right(t_data *data);

/*----------------mouse_hook.c-------------------*/

int		mlx_mouse_moving(int x, int y, void *params);

/*----------------utils.c---------------------*/

void	*ft_calloc(size_t count, size_t size);

/*----------------sprites.c---------------------*/

void	get_sprites(t_data *data);
void	order_sprite(t_data *data);
double	calc_dist(t_data *data, t_vec pos);

/*----------------door.c-------------------*/

void	open_door(t_data *data);

/*----------------mlx_handle.c------------------*/

void	re_draw(t_data *data);
void	mlx_handling(t_data *data);

/*----------------time.c------------------*/

long	get_time(void);

/*----------------move.c------------------*/

void	move(t_data *data);

#endif
