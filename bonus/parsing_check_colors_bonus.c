/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_colors_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/03/10 15:33:35 by pguignie         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d_bonus.h"

int	check_charset_commas(int j, char *color)
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

int	check_charset_digit(int j, char *color)
{
	j += 1;
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

int	check_color_digit(char *color, int nb_commas, int i)
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
	return (nb_commas);
}

int	define_color(char what, int nb, t_data *d, int multi)
{
	if (what == 'F' && (nb >= 0 && nb <= 255))
	{
		d->color_f += nb << multi;
		return (SUCCESS);
	}
	else if (what == 'C' && (nb >= 0 && nb <= 255))
	{
		d->color_c += nb << multi;
		return (SUCCESS);
	}
	return (ERROR);
}

void	check_colors(t_pars *pars, t_data *d, char *color, char what)
{
	int		i;
	char	**esp;
	int		nb;
	int		multi;

	i = 0;
	nb = 0;
	multi = 16;
	if (check_charset(color, what) == ERROR)
		ft_free_close_error("Error\nColors configuration", pars);
	esp = ft_split_parsing(color);
	while (esp[i])
	{
		nb = ft_atoi(esp[i]);
		if (define_color(what, nb, d, multi) == ERROR)
		{
			free_str(esp);
			ft_free_close_error("Error\nColors configuration", pars);
		}
		i++;
		multi -= 8;
	}
	free_str(esp);
}
