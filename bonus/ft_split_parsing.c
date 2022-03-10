/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkralik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:18 by mkralik           #+#    #+#             */
/*   Updated: 2022/03/10 15:27:47 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static size_t  count_words(const char *s)
{
	size_t  words;
	int     state;

	words = 0;
	state = 1;
	while (s && *s)
	{
		if (*s == ' ' || *s == ',' || *s == 'F' || *s == 'C')
			state = 1;
		else if (state == 1)
		{
			words++;
			state = 0;
		}
		s++;
	}
	return (words);
}

static size_t  sizeof_word(const char *s)
{
	size_t  i;

	i = 0;
	while (s[i] && (s[i] != ' ' && s[i] != ',' && s[i] != 'F' && s[i] != 'C'))
		i++;
	return (i);
}

static char    **free_tab(char **tab, size_t size)
{
	size_t  i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
	return (0);
}

char    **ft_split_parsing(const char *s)
{
    char    **tab;
    size_t  index;
    size_t  i;

    if (!s)
        return (NULL);
    tab = malloc(sizeof(char *) * (count_words(s) + 1));
    if (!tab)
        return (NULL);
    index = 0;
    while (count_words(s))
    {
        while (*s == ' ' || *s == ',' || *s == 'F' || *s == 'C')
            s++;
        tab[index] = malloc(sizeof(char) * (sizeof_word(s) + 1));
        if (!tab[index])
            return (free_tab(tab, index));
        i = 0;
        while (*s && (*s != ',' && *s != ' ' && *s != 'F' && *s != 'C'))
            tab[index][i++] = *s++;
        tab[index][i] = 0;
        index++;
    }
    tab[index] = 0;
    return (tab);
}
