/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:18:20 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/09 14:25:51 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	order_sprite(t_data *data)
{
	t_sprit	*s;
	t_sprit	tmp;
	t_vec	pos;

	s = data->sprite;
	pos = data->pos;
	while (s)
	{
		if (s->next && s->dist > s->next->dist)
		{
			tmp.pos = s->pos;
			tmp.dist = s->dist;
			s->pos = s->next->pos;
			s->dist = s->next->dist;
			s->next->pos = tmp.pos;
			s->next->dist = tmp.dist;
			s = data->sprite;
		}
		else
			s = s->next;
	}
}

static void	push_back(t_sprit **s, t_sprit *new)
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

double	calc_dist(t_data *data, t_vec pos)
{
	return (sqrt((data->pos.x - pos.x) * (data->pos.x - pos.x)
			+ (data->pos.y - pos.y) * (data->pos.y - pos.y)));
}

static t_sprit	*new_sprite(int i, int j, t_data *data)
{
	t_sprit	*new;

	new = (t_sprit *)malloc(sizeof(t_sprit));
	new->pos.x = j + 0.5;
	new->pos.y = data->pars->nb_line_of_file - 0.5 - i;
	new->dist = calc_dist(data, new->pos);
	new->next = NULL;
	return (new);
}

void	get_sprites(t_data *data)
{
	int		i;
	int		j;
	t_sprit	*s;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '2')
			{
				s = new_sprite(i, j, data);
				push_back(&data->sprite, s);
			}
			j++;
		}
		i++;
	}
	order_sprite(data);
}
