/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/15 15:37:21 by pguignie         ###   ########.fr       */
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

int main(int argc, char **argv, char **envp)
{
    t_data  data[1];

    if (check_arg(argc, argv, envp) == SUCCESS)
	{
		init_data(data);
		parsing(data, argv);
		execute(data);
	}
    return (0);
}
