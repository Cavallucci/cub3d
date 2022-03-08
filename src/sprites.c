/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:18:20 by pguignie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/08 16:08:42 by pguignie         ###   ########.fr       */
=======
/*   Updated: 2022/03/04 17:54:42 by paulguign        ###   ########.fr       */
>>>>>>> 224c9f41ca9cb57efd5f6aca3b0410084eb32afa
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

<<<<<<< HEAD
void	push_back(t_sprit **s, t_sprit *new)
=======
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
>>>>>>> 224c9f41ca9cb57efd5f6aca3b0410084eb32afa
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

<<<<<<< HEAD
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
=======
static t_sprit	*new_sprite(int i, int j, t_data *data)
{
	t_sprit	*new;

	new = (t_sprit *)malloc(sizeof(t_sprit));
	new->pos.x = j + 0.5;
	new->pos.y = data->pars->nb_line_of_file - 0.5 - i;
	new->dist = sqrt((data->pos.x - new->pos.x) * (data->pos.x - new->pos.x)
			+ (data->pos.y - new->pos.y) * (data->pos.y - new->pos.y));
	new->next = NULL;
	return (new);
}

void	get_sprites(t_data *data)
{
	int		i;
	int		j;
>>>>>>> 224c9f41ca9cb57efd5f6aca3b0410084eb32afa
	t_sprit	*s;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '2')
			{
<<<<<<< HEAD
				s = new_sprite(data->pars->nb_line_of_file - 1 - i, j);
=======
				s = new_sprite(i, j, data);
>>>>>>> 224c9f41ca9cb57efd5f6aca3b0410084eb32afa
				push_back(&data->sprite, s);
			}
			j++;
		}
		i++;
	}
<<<<<<< HEAD
	s = data->sprite;
	while (s)
	{
		printf("(%lf, %lf)\n", s->pos.x, s->pos.y);
		s = s->next;
	}
=======
	order_sprite(data);
>>>>>>> 224c9f41ca9cb57efd5f6aca3b0410084eb32afa
}
