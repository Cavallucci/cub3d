/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/09 16:11:18 by lcavallu         ###   ########.fr       */
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

void	ft_free_close_error(char *str, t_pars *pars)
{
	int	i;

	i = 0;
	if (pars->file_fd)
		close(pars->file_fd);
	if (pars->file)
		free_str(pars->file);
	if (pars->north)
		free_str(pars->north);
	if (pars->south)
		free_str(pars->south);
	if (pars->west)
		free_str(pars->west);
	if (pars->east)
		free_str(pars->east);
	if (pars->floor)
		free_str(pars->floor);
	if (pars->ceiling)
		free_str(pars->ceiling);
	ft_error(str);
}

void	free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (ERROR);
		i++;
	}
	return (SUCCESS);

}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int		i;
	int		d;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i + 1 < n)
		i++;
	d = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (!d || !n)
		return (0);
	else if (d < 0)
		return (-1);
	else
		return (1);
}

int	cmp_str(const char *s1, const char *s2)
{
	return (!ft_strncmp(s1, s2, ft_strlen(s1))
		&& !ft_strncmp(s1, s2, ft_strlen(s2)));
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	nb;

	nb = 0;
	sign = 1;
	while (*nptr == '\f' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == ' ')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + *nptr - 48;
		nptr++;
	}
	if (nb * sign > 2147483647)
		return (-1);
	return ((int)nb * sign);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
