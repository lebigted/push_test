/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:01:16 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/26 05:54:47 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_pile **pile)
{
	long int	temp;

	temp = (*pile)->value;
	(*pile)->value = (*pile)->next->value;
	(*pile)->next->value = temp;
	ft_putstr("sa\n");
	return (0);
}

int	push_b(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*temp;

	if (!(*pile_a))
		exit(0);
	temp = *pile_a;
	*pile_a = (*pile_a)->next;
	temp->next = *pile_b;
	*pile_b = temp;
	ft_putstr("pb\n");
	return (0);
}

int	push_a(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*temp;

	if (!(*pile_b))
		exit(0);
	temp = *pile_b;
	*pile_b = (*pile_b)->next;
	temp->next = *pile_a;
	*pile_a = temp;
	ft_putstr("pa\n");
	return (0);
}
