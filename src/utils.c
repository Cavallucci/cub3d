/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/08 19:27:57 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int	ft_strncmp_parsing(const char *s1, const char *s2)
{
	int		i;
	int		d;
	int		n;

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
