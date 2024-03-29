/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/03/14 11:23:55 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_nb_line(t_pars	*pars, t_data *d)
{
	char	*line;
	int		file;
	int		count_line;

	count_line = 0;
	file = open(pars->file_name, O_RDONLY);
	if (file < 0)
		ft_free_close_error("Error\nOpen map", d);
	line = get_next_line(file, &line);
	if (!line)
		ft_free_close_error("Error\nEmpty file", d);
	while (line)
	{
		free(line);
		line = get_next_line(file, &line);
		count_line++;
	}
	close(file);
	free(line);
	return (count_line);
}

void	check_informations(t_pars *pars, t_data *d)
{
	int	i;

	i = 0;
	pars->nb_line_of_file = get_nb_line(pars, d);
	pars->file = malloc(sizeof(char *) * (pars->nb_line_of_file + 1));
	while (i < pars->nb_line_of_file)
	{
		pars->file[i] = get_next_line(pars->file_fd, &pars->file[i]);
		i++;
	}
	pars->file[i] = NULL;
	close(pars->file_fd);
	if (i < 9)
		ft_free_close_error("Error\nFile configuration", d);
	collect_textures(pars);
	verify_textures(pars, d);
}

void	change_map(t_pars *pars)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (pars->nb_line_of_file + 1));
	while (pars->data->map[i])
	{
		new_map[i] = put_file_in_map(pars, new_map, i);
		i++;
	}
	new_map[i] = NULL;
	free(pars->data->map);
	pars->data->map = new_map;
}

void	check_map(t_pars *pars, int i, t_data *d)
{
	int	j;
	int	bigger_line;

	j = 0;
	bigger_line = 0;
	pars->nb_line_of_file -= i;
	pars->data->map = malloc(sizeof(char *) * (pars->nb_line_of_file + 1));
	while (pars->file[i])
	{
		pars->data->map[j] = pars->file[i];
		bigger_line = ft_strlen(pars->file[i]);
		if (bigger_line > pars->nb_bigger_line)
			pars->nb_bigger_line = bigger_line;
		i++;
		j++;
	}
	pars->data->map[j] = NULL;
	change_map(pars);
	if (verify_map(pars) == ERROR)
		ft_free_close_error("Error\nMap configuration", d);
}

void	parsing(t_data *d, char **argv)
{
	t_pars	*pars;
	int		i;

	pars = (t_pars *)malloc(sizeof(t_pars));
	i = 0;
	init_pars(pars, argv, d);
	check_informations(pars, d);
	while (!cmp_str(pars->file[i], pars->ceiling))
		i++;
	i++;
	while (i < pars->nb_line_of_file && (ft_is_space(pars->file[i]) == SUCCESS
			|| pars->file[i][0] == 0))
		i++;
	check_map(pars, i, d);
}
