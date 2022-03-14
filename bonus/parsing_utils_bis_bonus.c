/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bis_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/03/14 11:01:54 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_charset(char *color, char what)
{
	int	i;
	int	nb_commas;

	i = 0;
	nb_commas = 0;
	while (color[i] == ' ')
		i++;
	if (color[i] != what)
		return (ERROR);
	i += 1;
	while (color[i])
	{
		nb_commas = check_color_digit(color, nb_commas, i);
		if (nb_commas == -1)
			return (ERROR);
		i++;
	}
	if (nb_commas != 2 && (color[0] == ',' || color[ft_strlen(color)] == ','))
		return (ERROR);
	return (SUCCESS);
}

int	ft_strncmp_parsing(const char *s1, const char *s2)
{
	int	i;
	int	d;
	int	n;

	i = 0;
	d = 0;
	if (!s1 || !s2)
		return (0);
	n = ft_strlen(s2);
	while (s1[i])
		i++;
	i -= n;
	while (s1[i] && s1[i] == s2[d] && d + 1 < n)
	{
		d++;
		i++;
	}
	d = (unsigned char)s1[i] - (unsigned char)s2[d];
	if (!d || !n)
		return (0);
	else if (d < 0)
		return (-1);
	else
		return (1);
}

int	ft_error(char *str)
{
	printf("%s\n", str);
	exit(ERROR);
}

void	ft_free_close_error(char *str, t_data *data)
{
	printf("%s\n", str);
	win_close(data, 1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
