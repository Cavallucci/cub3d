/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:14:22 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/16 14:25:20 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)b;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	b = (void *)temp;
	return (b);
}

static void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (size > 0 && i < count)
	{
		ft_memset(ptr + (i * size), 0, size);
		i++;
	}
	return (ptr);
}

t_mlx	*init_mlx(t_data *data)
{
	t_mlx	*ptr;

	(void)data;
	ptr = ft_calloc(1, sizeof(t_mlx));
	if (!ptr)
		return (NULL);
	ptr->mlx_ptr = mlx_init();
	if (!ptr->mlx_ptr)
		return (NULL);
	ptr->screen = init_vec(1080, 720);
	ptr->win = mlx_new_window(ptr->mlx_ptr, ptr->screen.x,
			ptr->screen.y, "cub3d");
	ptr->img = mlx_new_image(ptr->mlx_ptr, ptr->screen.x, ptr->screen.y);
	if (!ptr->win || !ptr->img)
		return (NULL);
	ptr->buffer = mlx_get_data_addr(ptr->img, &ptr->pixel_bits,
			&ptr->line_bytes, &ptr->endian);
	if (!ptr->buffer)
		return (NULL);
	return (ptr);
}
