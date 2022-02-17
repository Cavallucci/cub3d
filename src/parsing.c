/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/17 15:30:29 by pguignie         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int	get_nb_line(t_pars	*pars)
{
	char	*line;
	int		file;
	int		count_line;

	count_line = 0;
	file = open(pars->file_name, O_RDONLY);
	if (file < 0)
		ft_free_close_error("Error\nOpen map", pars);
	line = get_next_line(file, &line);
	if (!line)
		ft_free_close_error("Error\nEmpty file", pars);
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

void    check_informations(t_pars *pars)
{
    int i;

    i = 0;
    pars->nb_line_of_file = get_nb_line(pars);
    pars->file = malloc(sizeof(char *) * pars->nb_line_of_file);
    while (i < pars->nb_line_of_file)
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

char	*put_file_in_map(t_pars *pars, char **new_map, int i)
{
	int		k;

	k = 0;
	new_map[i] = malloc(sizeof(char) * (pars->nb_bigger_line + 1));
	while (pars->data->map[i][k])
	{
		new_map[i][k] = pars->data->map[i][k];
		k++;
	}
	while (k < pars->nb_bigger_line)
	{
		new_map[i][k] = ' ';
		k++;
	}
	new_map[i][k] = '\0';
	return (new_map[i]);
}

void	change_map(t_pars *pars)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * pars->nb_line_of_file);
	while (pars->data->map[i])
	{
		new_map[i] = put_file_in_map(pars, new_map, i);
		i++;
	}
	new_map[i] = NULL;
	free(pars->data->map);
	pars->data->map = new_map;
}

void	check_map(t_pars *pars)
{
	int	i;
	int	j;
	int	bigger_line;

	i = 0;
	j = 0;
	bigger_line = 0;
	while (!cmp_str(pars->file[i], pars->ceiling))
		i++;
	i++;
	while (i < pars->nb_line_of_file && (ft_is_space(pars->file[i]) == SUCCESS
		|| pars->file[i][0] == 0))
		i++;
	pars->nb_line_of_file  -= i;
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
	{
		free(pars->data->map);
		ft_free_close_error("Error\nMap configuration", pars);
	}
}

void	parsing(t_data *d, char **argv)
{
	t_pars	pars[1];

	init_pars(pars, argv, d);
	check_informations(pars);
	check_map(pars);
	//si textures ok, verifir la map
	//si map ok, mettre la map dans un ** a part

}
