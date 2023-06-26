/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:07:11 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/26 10:16:56 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_in_str(const char *s, char c)
{
	size_t	inword;
	size_t	count;

	inword = 0;
	count = 0;
	while (s[inword] && s[inword] == c)
		inword++;
	if (s[inword] && s[inword] == 0)
		return (0);
	while (s[inword])
	{
		count++;
		while (s[inword] && s[inword] != c)
			inword++;
		while (s[inword] && s[inword] == c)
			inword++;
	}
	return (count);
}

static char	*find_word(char *s, int last)
{
	char	*new_str;

	new_str = ft_calloc(last + 1, sizeof(char));
	if (!new_str || !s)
		return (NULL);
	while (last--)
		new_str[last] = s[last];
	return (new_str);
}

char	**ft_split_bis(char const *s, char **tstr, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)s;
	while (*str)
	{
		if (*str != c)
		{
			j = 0;
			while (*str && *str != c)
			{
				j++;
				str++;
			}
			tstr[i++] = find_word((char *)str - j, j);
		}
		else
			str++;
	}
	return (tstr);
}

char	**ft_split(char const *s, char c)
{
	size_t	nbr_word;
	char	**tstr;

	if (!s)
		return (NULL);
	nbr_word = word_in_str(s, c);
	tstr = ft_calloc((word_in_str((char *)s, c) + 1), sizeof(char *));
	if (!tstr)
		return (NULL);
	return (ft_split_bis(s, tstr, c));
}
