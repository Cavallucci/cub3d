/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/07 19:21:57 by lcavallu         ###   ########.fr       */
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
	if (!envp[0])
		exit(EXIT_FAILURE);
	if (argc == 2 && !check_file(argv[1]))
	{
		put_image(data, info);
	}
	else
		ft_putstr("Error\nargument\n");
	return (0);
}

//check nombre d'arguments
//check si l'arg1(la map) est un ".cub"
//check la map
//si map ok, ca donne quoi sur une minimap ?
