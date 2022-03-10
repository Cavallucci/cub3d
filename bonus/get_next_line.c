/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:58:59 by lcavallu          #+#    #+#             */
/*   Updated: 2022/03/10 15:28:04 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*source;
	size_t		i;

	dst = dest;
	source = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n && dst[i])
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(sizeof(const char) * ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

char	*get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			ret;

	ret = 1;
	if (read(fd, 0, 0) < 0 || !line || BUFFER_SIZE <= 0)
		return (NULL);
	*line = ft_strdup("");
	*line = ft_strjoin(*line, buf);
	while (!is_charset(*line, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	*line = get_previous(*line);
	get_next(buf);
	if (ret == 0)
	{
		free(*line);
		return (NULL);
	}
	return (*line);
}
