/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/09 12:29:44 by lcavallu         ###   ########.fr       */
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

void	verify_textures(t_pars *pars)
{
	check_array_texture(pars->north);
	check_array_texture(pars->south);
	check_array_texture(pars->west);
	check_array_texture(pars->east);
	check_array_texture(pars->floor);
	check_array_texture(pars->ceiling);
	if (cmp_str(pars->north[0], "NO") || cmp_str(pars->south[0], "SO")
		|| cmp_str(pars->west, "WE");
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
