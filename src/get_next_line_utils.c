/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:29:00 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/08 19:31:23 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	is_charset(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_previous(char *st)
{
	int		i;
	char	*new;

	i = 0;
	if (!st)
		return (NULL);
	while (st[i] && st[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!new)
	{
		free(st);
		return (0);
	}
	i = 0;
	while (st[i] && st[i] != '\n')
	{
		new[i] = st[i];
		i++;
	}
	new[i] = '\0';
	free(st);
	return (new);
}

char	*get_next(char *st)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!st)
		return (NULL);
	while (st[i] && st[i] != '\n')
		i++;
	if (st[i] == '\n')
		i++;
	str = st;
	j = 0;
	while (st[i])
	{
		str[j] = st[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	s1 = NULL;
	return (join);
}
