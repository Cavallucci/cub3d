/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/08 18:39:37 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int main(int argc, char **argv, char **envp)
{
    t_data  data[1];

    if (check_arg(argc, argv, envp) == SUCCESS)
	{
		init_data(data);
		parsing(data, argv);
	}
    return (0);
}

//check nombre d'arguments --> FAIT
//check si l'arg1(la map) est un ".cub" --> FAIT
//check si il s'ouvre bien --> FAIT
//check la config du fichier .cub (6 infos, espaces OK)
//check la map
//si map ok, ca donne quoi sur une minimap ?
