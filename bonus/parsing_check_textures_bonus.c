/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_textures_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/03/14 11:26:09 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_array_texture(char **texture, t_data *d)
{
	int	i;

	i = 0;
	while (texture[i])
		i++;
	if (i != 2)
		ft_free_close_error("Error\nTextures configuration", d);
}

int	fill_mlx_ptr(t_data *d)
{
	d->door->mlx_ptr = mlx_get_data_addr(d->door->img, &d->door->pixel_bits,
			&d->door->line_bytes, &d->door->endian);
	d->north->mlx_ptr = mlx_get_data_addr(d->north->img, &d->north->pixel_bits,
			&d->north->line_bytes, &d->north->endian);
	d->south->mlx_ptr = mlx_get_data_addr(d->south->img, &d->south->pixel_bits,
			&d->south->line_bytes, &d->south->endian);
	d->west->mlx_ptr = mlx_get_data_addr(d->west->img, &d->west->pixel_bits,
			&d->west->line_bytes, &d->west->endian);
	d->east->mlx_ptr = mlx_get_data_addr(d->east->img, &d->east->pixel_bits,
			&d->east->line_bytes, &d->east->endian);
	d->sprite_img->mlx_ptr = mlx_get_data_addr(d->sprite_img->img,
			&d->sprite_img->pixel_bits, &d->sprite_img->line_bytes,
			&d->sprite_img->endian);
	if (!d->north->mlx_ptr || !d->south->mlx_ptr || !d->west->mlx_ptr
		|| !d->east->mlx_ptr || !d->door->mlx_ptr || !d->sprite_img->mlx_ptr)
		return (ERROR);
	else
		return (SUCCESS);
}

void	check_path_textures(t_pars *pars, t_data *d)
{	
	d->north = malloc(sizeof(t_mlx));
	d->south = malloc(sizeof(t_mlx));
	d->west = malloc(sizeof(t_mlx));
	d->east = malloc(sizeof(t_mlx));
	d->door = malloc(sizeof(t_mlx));
	d->sprite_img = malloc(sizeof(t_mlx));
	d->sprite_img->img = mlx_xpm_file_to_image(d->mlx->mlx_ptr, pars->sprite[1],
			&(d->sprite_img->img_width), &(d->sprite_img->img_height));
	d->door->img = mlx_xpm_file_to_image(d->mlx->mlx_ptr, pars->door[1],
			&(d->door->img_width), &(d->door->img_height));
	d->north->img = mlx_xpm_file_to_image(d->mlx->mlx_ptr, pars->north[1],
			&(d->north->img_width), &(d->north->img_height));
	d->south->img = mlx_xpm_file_to_image(d->mlx->mlx_ptr, pars->south[1],
			&d->south->img_width, &d->south->img_height);
	d->west->img = mlx_xpm_file_to_image(d->mlx->mlx_ptr, pars->west[1],
			&d->west->img_width, &d->west->img_height);
	d->east->img = mlx_xpm_file_to_image(d->mlx->mlx_ptr, pars->east[1],
			&d->east->img_width, &d->east->img_height);
	if (!d->north->img || !d->south->img || !d->west->img
		|| !d->east->img || !d->door->img || !d->sprite_img->img)
		ft_free_close_error("Error\nPath textures", d);
	if (fill_mlx_ptr(d) == ERROR)
		ft_free_close_error("Error\nPath textures", d);
}

void	verify_textures(t_pars *pars, t_data *d)
{
	check_array_texture(pars->north, d);
	check_array_texture(pars->south, d);
	check_array_texture(pars->west, d);
	check_array_texture(pars->east, d);
	check_array_texture(pars->door, d);
	check_array_texture(pars->sprite, d);
	if (!cmp_str(pars->north[0], "NO") || !cmp_str(pars->south[0], "SO")
		|| !cmp_str(pars->west[0], "WE") || !cmp_str(pars->east[0], "EA")
		|| !cmp_str(pars->door[0], "D") || !cmp_str(pars->sprite[0], "SP"))
		ft_free_close_error("Error\nFile configuration", d);
	check_path_textures(pars, d);
	check_colors(d, pars->floor, 'F');
	check_colors(d, pars->ceiling, 'C');
}
