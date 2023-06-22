/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 07:22:54 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/20 15:32:02 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	g_index(t_pile *pile, int nb)
{
	int			i;
	int	res;

	i = 0;
	res = 0;
	while (i < pile->size)
	{
		if (nb > pile->tab[i])
			res++;
		i++;
	}
	return (0);
}

long int	*s_index(t_pile *pile)
{
	int	*index;
	int			i;

	index = malloc(sizeof(long int) * pile->size);
	if (!index)
		return (NULL);
	i = 0;
	while (i < pile->size)
	{
		index[i] = g_index(pile, pile->tab[i]);
		i++;
	}
	return (0);
}
