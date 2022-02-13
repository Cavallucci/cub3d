/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/13 19:37:48 by lcavallu         ###   ########.fr       */
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
	count_line++;
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
    pars->nb_line_of_file = get_nb_line(pars); //pour pouvoir malloc pars->file
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

void	check_map(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!cmp_str(pars->file[i], pars->ceiling))
		i++;
	i++;
	while (i < pars->nb_line_of_file && (ft_is_space(pars->file[i]) == SUCCESS
		|| pars->file[i][0] == 0))
		i++;
	pars->nb_line_of_file  -= i;
	pars->data->map = malloc(sizeof(char *) * pars->nb_line_of_file); 
	while (pars->file[i])
	{
		pars->data->map[j] = pars->file[i];
		i++;
		j++;
	}
	pars->data->map[j] = NULL;
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
	printf("parsing ok\n");
	//si textures ok, verifir la map
	//si map ok, mettre la map dans un ** a part

}
