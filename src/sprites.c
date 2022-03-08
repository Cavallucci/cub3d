/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:18:20 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/08 16:08:42 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	push_back(t_sprit **s, t_sprit *new)
{
	t_sprit	*tmp;

	if (!*s)
		*s = new;
	else
	{
		tmp = *s;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_sprit	*new_sprite(int i, int j)
{
	t_sprit	*s;

	s = (t_sprit *)malloc(sizeof(t_sprit));
	s->pos.x = j + 0.5;
	s->pos.y = i + 0.5;
	s->next = NULL;
	return (s);
}

/*
void	switch_sprite(t_sprit **a, t_sprit **b)
{
}
*/

void	get_sprites(t_data *data)
{
	int			i;
	int			j;
	t_sprit	*s;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '2')
			{
				s = new_sprite(data->pars->nb_line_of_file - 1 - i, j);
				push_back(&data->sprite, s);
			}
			j++;
		}
		i++;
	}
	s = data->sprite;
	while (s)
	{
		printf("(%lf, %lf)\n", s->pos.x, s->pos.y);
		s = s->next;
	}
}
