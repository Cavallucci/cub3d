/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/16 14:35:36 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int check_charset_commas(int j, char *color)
{
	j += 1;
	if (ft_isdigit(color[j]))
		return (SUCCESS);
	else
	{
		while (color[j] && color[j] == ' ')
			j++;
		if (color[j] == ',')
			return (ERROR);
	}
	return (SUCCESS);
}

int check_charset_digit(int j, char *color)
{
	j +=1;
	while (color[j] && ft_isdigit(color[j]))
		j++;
	while (color[j] && color[j] == ' ')
		j++;
	if (color[j] == ',')
		return (SUCCESS);
	else if (ft_isdigit(color[j]))
		return (ERROR);
	return (SUCCESS);
}

int check_charset(char *color, char what)
{
	int i;
	int nb_commas;

	i = 0;
	nb_commas = 0;
	while (color[i] == ' ')
		i++;
	if (color[i] != what)
		return (ERROR);
	i += 1;
	while (color[i])
	{
		if (!ft_isdigit(color[i]) && color[i] != ' ' && color[i] != ',')
			return (ERROR);
		if (color[i] == ',')
		{
			if (check_charset_commas(i, color) == ERROR)
				return (ERROR);
			nb_commas++;
		}
		if (ft_isdigit(color[i]))
			if (check_charset_digit(i, color) == ERROR)
				return (ERROR);
		i++;
	}
	if (nb_commas != 2)
		return (ERROR);
	if (color[0] == ',' || color[ft_strlen(color)] == ',')
		return (ERROR);
	return (SUCCESS);
}

void    check_colors(t_pars *pars, t_data *d, char *color, char what)
{
	int     i;
	char    **esp;
	int     nb;
	int		multi;

	i = 0;
	nb = 0;
	multi = 16;
	if (check_charset(color, what) == ERROR)
		ft_free_close_error("Error\nColors configuration", pars); //destroy im?
	esp = ft_split_parsing(color);
	while (esp[i])
	{
		nb = ft_atoi(esp[i]);
		if (what == 'F' && (nb >= 0 && nb <= 255))
			d->color_f += nb << multi;
		else if (what == 'C' && (nb >= 0 && nb <= 255))
			d->color_c += nb << multi;
		else
		{
			free_str(esp);
			ft_free_close_error("Error\nColors configuration", pars); //destroy im?
		}
		i++;
		multi -= 8;
	}
	free_str(esp);
}
