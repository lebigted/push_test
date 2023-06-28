/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:25:14 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/28 11:31:04 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pilesize(t_pile *pile)
{
	int	size;

	size = 0;
	while (pile)
	{
		size++;
		pile = pile->next;
	}
	return (size);
}

int	check_tri(t_pile **pile)
{
	t_pile	*tmp;
	int		i;

	tmp = *pile;
	i = ft_pilesize(tmp);
	while (i > 0 && tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
		i--;
	}
	return (0);
}

void	get_max(t_pile *pile_a, int *maxnum, int *maxbit)
{
	*maxnum = ft_pilesize(pile_a) - 1;
	while ((*maxnum >> *maxbit) != 0)
		(*maxbit)++;
}

t_pile	*radix_sort(t_pile *pile_a, t_pile *pile_b)
{
	int		j;
	int		i;
	int		maxbit;
	int		maxnum;

	j = 0;
	get_max(pile_a, &maxnum, &maxbit);
	while (pile_b || !is_sort(pile_a))
	{
		i = ft_pilesize(pile_a);
		while (--i >= 0)
		{
			if (((pile_a->value >> j) & 1) == 1)
				rotate(&pile_a);
			else
				push_b(&pile_a, &pile_b);
		}
		while (pile_b)
			push_a(&pile_a, &pile_b);
		j++;
	}
	return (pile_a);
}
