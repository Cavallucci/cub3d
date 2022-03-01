/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:49:45 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/28 16:18:15 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (check_arg(argc, argv, envp) == SUCCESS)
	{
		data = (t_data *)ft_calloc(1, sizeof(t_data));
		if (!data)
			return (0);
		data->mlx = init_mlx();
		parsing(data, argv);
		render(data);
	}
	return (0);
}
