/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/07 20:13:04 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int	check_file(char *arg)
{
	if (!arg)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	void	*mlx;
	void	*mlx_win;

	if (!envp[0])
		exit(EXIT_FAILURE);
	if (argc == 2 && !check_file(argv[1]))
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 5 * 60, 5 * 60, "cub3d");
//		save_image(data);
//		mlx_hook(mlx_win, 2, 1L << 0, ft_close, data);
//		mlx_hook(mlx_win, 17, 0L, ft_free_exit, data);
		mlx_loop(mlx);
	}
	else
		printf("Error\nargument\n");
	return (0);
}

//check nombre d'arguments
//check si l'arg1(la map) est un ".cub"
//check la map
//si map ok, ca donne quoi sur une minimap ?
