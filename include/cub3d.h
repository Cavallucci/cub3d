/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/10 15:29:45 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# define ERROR 1
# define SUCCESS 0

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define BUFFER_SIZE				1
# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3
# define ESC						65307
# define W							119
# define A							97
# define S							115
# define D							100

typedef struct s_pars
{
	int				file_fd;
	char			*file_name;
	char			**file;
	char			**north;
	char			**south;
	char			**west;
	char			**east;
	char			*floor;
	char			*ceiling;
	struct s_data	*data;
}	t_pars;

typedef struct s_data
{
	void	*mlx;
	void	*img[4];
	int		color_f[3];
	int		color_c[3];
	t_pars	*pars;
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

int		get_nb_line(t_pars  *pars);
void	collect_textures(t_pars *pars);
void	parsing(t_data *d, char **argv);

/*----------------parsing_init.c--------------*/

void	init_data(t_data *data);
void	init_pars(t_pars *pars, char **argv, t_data *d);

/*----------------parsing_utils.c-----------------*/

int		ft_strncmp_parsing(const char *s1, const char *s2);
int		ft_error(char *str);
void	ft_free_close_error(char *str, t_pars *pars);
int		ft_is_space(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		cmp_str(const char *s1, const char *s2);
void	free_str(char **str);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
/*----------------ft_split.c-----------------*/

char	**ft_split(const char *s, char c);

/*----------------parsing_check.c-----------------*/

void    check_array_texture(char **texture, t_pars *pars);
void    verify_textures(t_pars *pars);
int		check_array_color(char **color, char what, t_data *d);
void	check_path_textures(t_pars *pars, t_data *d);
void    fill_colors(char **esp, t_pars *pars, t_data *d);
int		check_charset(char *color, char what);
void	check_colors(t_pars *pars, t_data *d, char *color, char what);
void	verify_textures(t_pars *pars);
int		check_arg(int argc, char **argv, char **envp);
void	check_informations(t_pars *pars);

#endif
