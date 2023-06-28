/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 06:42:46 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/28 11:28:09 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_pile **pile_a, t_pile **min, int *min_index)
{
	t_pile	*tmp;
	int		index;

	tmp = *pile_a;
	*min = tmp;
	*min_index = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->value < (*min)->value)
		{
			*min = tmp;
			*min_index = index;
		}
		tmp = tmp->next;
		index++;
	}
}

void	rotate_to_min(t_pile **pile_a, t_pile *min, int min_index)
{
	if (min_index > pile_size(*pile_a) / 2)
		while ((*pile_a) != min)
			reverse_rotate(pile_a);
	else
		while ((*pile_a) != min)
			rotate(pile_a);
}

void	get_push_min(t_pile **pile_a, t_pile **pile_b, int n)
{
	t_pile	*min;
	int		min_index;

	while (n--)
	{
		find_min(pile_a, &min, &min_index);
		rotate_to_min(pile_a, min, min_index);
		push_b(pile_a, pile_b);
	}
}
