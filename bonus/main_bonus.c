/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:49:45 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 15:30:38 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

static int	init_keys(t_data *data)
{
	data->key = (t_key *)malloc(sizeof(t_key));
	if (!data->key)
	{
		free_data(data);
		return (0);
	}
	data->key->w = 0;
	data->key->a = 0;
	data->key->s = 0;
	data->key->d = 0;
	data->key->left = 0;
	data->key->right = 0;
	return (1);
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
		if (!init_keys(data))
			return (1);
		parsing(data, argv);
		get_sprites(data);
		render(data);
	}
	return (0);
}
