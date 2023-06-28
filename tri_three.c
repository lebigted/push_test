/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:34:54 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/28 09:12:18 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_pile(t_pile *pile)
{
	while (pile)
	{
		if (!pile->next)
			return (1);
		if (pile->value < pile->next->value)
			pile = pile->next;
		else
			return (0);
	}
	return (1);
}

int	check_case(t_pile *pile)
{
	int	a;
	int	b;
	int	c;

	if (pile == NULL || pile->next == NULL || pile->next->next == NULL)
		return (-1);
	a = pile->value;
	b = pile->next->value;
	c = pile->next->next->value;
	if (a > b && a < c)
		return (1);
	if (a > b && b > c)
		return (2);
	if (a > b && a > c)
		return (3);
	if (a < b && a < c)
		return (4);
	if (a < b && a > c)
		return (5);
	else
		return (0);
}

t_pile	*sort_list_of_three(t_pile *pile_a)
{
	if (sort_pile(pile_a))
		return (pile_a);
	if (check_case(pile_a) == 1)
	{
		swap(&pile_a);
	}
	else if (check_case(pile_a) == 2)
	{
		swap(&pile_a);
		reverse_rotate(&pile_a);
	}
	else if (check_case(pile_a) == 3)
		rotate(&pile_a);
	else if (check_case(pile_a) == 4)
	{
		swap(&pile_a);
		rotate(&pile_a);
	}
	else if (check_case(pile_a) == 5)
		reverse_rotate(&pile_a);
	return (pile_a);
}
