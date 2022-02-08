/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/08 19:35:45 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int	check_arg(int argc, char **argv, char **envp)
{
	if (!envp[0])
		ft_error("Error\nNo env");
	if (argc != 2)
		ft_error("Error\nargument");
	if (ft_strncmp_parsing(argv[1], ".cub") != SUCCESS)
		ft_error("Error\nFile extension");
	return (0);
}

void	init_data(t_data *d)
{
	d->pars = NULL;
}

void	init_pars(t_pars *pars, char **argv)
{
	pars->file_name = argv[1];
	pars->file_fd = open(pars->file_name, O_RDONLY);
	if (pars->file_fd < 0)
		ft_error("Error\nOpen map");
	pars->file = NULL;
	pars->north = NULL;
	pars->south = NULL;
	pars->west = NULL;
	pars->east = NULL;
	pars->floor = NULL;
	pars->ceiling = NULL;
}

int	get_nb_line(t_pars	*pars)
{
	char	*line;
	int		file;
	int		count_line;

	count_line = 0;
	file = open(pars->file_name, O_RDONLY);
	if (file < 0)
		ft_error("Error\nOpen map");
	line = get_next_line(file, &line);
	if (!line)
		ft_error("Error\nEmpty file");
	count_line++;
	while (line)
	{
		line = get_next_line(file, &line);
		count_line++;
	}
	close(file);
	free(line);
	return (count_line);
}

void	check_informations(t_pars *pars)
{
	int	i;
	int	nb_line_of_file;

	i = 0;
	nb_line_of_file = get_nb_line(pars); //pour pouvoir malloc pars->file
	pars->file = malloc(sizeof(char *) * nb_line_of_file);
	while (i < nb_line_of_file)
	{
		pars->file[i] = get_next_line(pars->file_fd, &pars->file[i]);
		i++;
	}
	printf("line3 = %s\n", pars->file[2]);
}

void	parsing(t_data *d, char **argv)
{
	t_pars	pars[1];
(void)d;
	init_pars(pars, argv);
	check_informations(pars);
}
