/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/09 18:24:38 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int check_arg(int argc, char **argv, char **envp)
{
	if (!envp[0])
		ft_error("Error\nNo env");
	if (argc != 2)
		ft_error("Error\nargument");
	if (ft_strncmp_parsing(argv[1], ".cub") != SUCCESS)
		ft_error("Error\nFile extension");
	return (0);
}

void	check_array_texture(char **texture, t_pars *pars)
{
	int i;

	i = 0;
	while (texture[i])
		i++;
	if (i != 2)
		ft_free_close_error("Error\nTextures configuration", pars);
}

int	check_array_color(char **color)
{
	int i;

	i = 0;
	while (color[i])
	{
		if (color[i])
			i++;
	}
	return (SUCCESS);
}

void	check_path_textures(t_pars *pars, t_data *d)
{
	int	img_width;
	int	img_height;

	d->img[NORTH] = mlx_xpm_file_to_image(d->mlx, pars->north[1], &img_width,
			&img_height);
	d->img[SOUTH] = mlx_xpm_file_to_image(d->mlx, pars->south[1], &img_width,
			&img_height);
	d->img[WEST] = mlx_xpm_file_to_image(d->mlx, pars->west[1], &img_width,
			&img_height);
	d->img[EAST] = mlx_xpm_file_to_image(d->mlx, pars->east[1], &img_width,
			&img_height);
	if (!d->img[NORTH] || !d->img[SOUTH] || !d->img[WEST] || !d->img[EAST])
		ft_free_close_error("Error\nPath textures", pars);
	//destroy image ??
}

void	fill_colors(char **esp, t_pars *pars, t_data *d)
{
	(void)esp;
	(void)pars;
	(void)d;
}

int	check_charset_commas(int j, char *color)
{//segfault si ya pas de j + 1 ??
	j += 1;
	if (ft_isdigit(color[j]))
		return (SUCCESS);
	else
	{
		while (color[j] && color[j] == ' ')
			j++;
		if (color[j] == ',')
			return (ERROR);
	}
	return (SUCCESS);
}

int	check_charset_digit(int j, char *color)
{//segfault si pas de j + 1 ??
	j +=1;
	while (color[j] && ft_isdigit(color[j]))
		j++;
	while (color[j] && color[j] == ' ')
		j++;
	if (color[j] == ',')
		return (SUCCESS);
	else if (ft_isdigit(color[j]))
		return (ERROR);
	return (SUCCESS);
}

int	check_charset(char *color)
{
	int	i;
	int	nb_commas;

	i = 0;
	nb_commas = 0;
	while (color[i])
	{
		printf("color = %s color[i] = %c\n", color, color[i]);
		if (!ft_isdigit(color[i]) && color[i] != ' ' && color[i] != ',')
			return (ERROR);
		if (color[i] == ',')
		{
			if (check_charset_commas(i, color) == ERROR)
				return (ERROR);
			nb_commas++;
		}
		if (ft_isdigit(color[i]))
			if (check_charset_digit(i, color) == ERROR)
				return (ERROR);
		i++;
	}
	if (nb_commas != 2)
			return (ERROR);
	if (color[0] == ',' || color[ft_strlen(color)] == ',')
		return (ERROR);
	return (SUCCESS);
}

void	check_colors(t_pars *pars, t_data *d, char **color)
{
	char	**esp;
	//	char	**commas;

	if (check_charset(color[1]) == ERROR) 
		ft_free_close_error("Error\nColors configuration", pars); //destroy im?
	esp = ft_split(color[1], ' ');
	if (check_array_color(esp) == ERROR)
	{
		free_str(esp);
		//destroy image ?
		ft_free_close_error("Error\nColors configuration", pars);
	}
	fill_colors(esp, pars, d);
	//esp[0] == couleurs sans espaces
	//split les espaces
	//split les virgules
	// couleurs = 3
	//digit range de 0 a 255
	//separer en 2 int **
}

void	verify_textures(t_pars *pars)
{
	check_array_texture(pars->north, pars);
	check_array_texture(pars->south, pars);
	check_array_texture(pars->west, pars);
	check_array_texture(pars->east, pars);
	if (!cmp_str(pars->north[0], "NO") || !cmp_str(pars->south[0], "SO")
			|| !cmp_str(pars->west[0], "WE") || !cmp_str(pars->east[0], "EA")
			|| !cmp_str(pars->floor[0], "F") || !cmp_str(pars->ceiling[0], "C"))
		ft_free_close_error("Error\nFile configuration", pars);
	//	check_path_textures(pars, pars->data);
	check_colors(pars, pars->data, pars->floor);
	check_colors(pars, pars->data, pars->ceiling);
}

void    check_informations(t_pars *pars)
{
	int i;
	int nb_line_of_file;

	i = 0;
	nb_line_of_file = get_nb_line(pars); //pour pouvoir malloc pars->file
	pars->file = malloc(sizeof(char *) * nb_line_of_file);
	while (i < nb_line_of_file)
	{
		pars->file[i] = get_next_line(pars->file_fd, &pars->file[i]);
		i++;
	}
	close(pars->file_fd);
	if (i < 9)
		ft_free_close_error("Error\nFile configuration", pars);
	collect_textures(pars);
	verify_textures(pars);
}
