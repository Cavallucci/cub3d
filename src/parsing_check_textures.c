/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/13 13:59:30 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

void    collect_textures(t_pars *pars)
{
    int i;
    int count;

    i = 0;
    count = 1;
    while (count < 7)
    {
        while (pars->file[i] && ft_is_space(pars->file[i]) == SUCCESS)
            i++;
        if (count == 1)
            pars->north = ft_split(pars->file[i], ' ');
        else if (count == 2)
            pars->south = ft_split(pars->file[i], ' ');
        else if (count == 3)
            pars->west = ft_split(pars->file[i], ' ');
        else if (count == 4)
            pars->east = ft_split(pars->file[i], ' ');
        else if (count == 5)
            pars->floor = pars->file[i];
        else if (count == 6)
            pars->ceiling = pars->file[i];
        i++;
        count++;
    }
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

void	verify_textures(t_pars *pars)
{
	check_array_texture(pars->north, pars);
	check_array_texture(pars->south, pars);
	check_array_texture(pars->west, pars);
	check_array_texture(pars->east, pars);
	if (!cmp_str(pars->north[0], "NO") || !cmp_str(pars->south[0], "SO")
			|| !cmp_str(pars->west[0], "WE") || !cmp_str(pars->east[0], "EA"))
		ft_free_close_error("Error\nFile configuration", pars);
	//	check_path_textures(pars, pars->data);
	check_colors(pars, pars->data, pars->floor, 'F');
	check_colors(pars, pars->data, pars->ceiling, 'C');
}
