/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_five.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:30:04 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/28 11:30:37 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_size(t_pile *pile)
{
	t_pile	*tmp;
	int		size;

	size = 0;
	tmp = pile;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	sort_invers(t_pile **pile_a)
{
	t_pile	*tmp;
	int		i;

	tmp = *pile_a;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			i++;
		else
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_reverse_sorted(t_pile **pile_a)
{
	t_pile	*tmp;

	tmp = *pile_a;
	while (tmp->next != NULL)
	{
		if (tmp->value <= tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	verif_pile(t_pile **pile_a)
{
	t_pile	*prev;
	t_pile	*last;

	last = *pile_a;
	prev = NULL;
	if (is_reverse_sorted(pile_a))
	{
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *pile_a;
		*pile_a = last;
	}
}

t_pile	*sort_list_of_five(t_pile *pile_a, t_pile *pile_b)
{
	int	i;

	i = 0;
	if (sort_invers(&pile_a) == 0)
		verif_pile(&pile_a);
	else
		get_push_min(&pile_a, &pile_b, 2);
	pile_a = sort_list_of_three(pile_a);
	while (i < 2)
	{
		push_a(&pile_a, &pile_b);
		i++;
	}
	return (pile_a);
}
