/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:17:20 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/28 08:42:57 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*temp;

	if (!(*pile) || !(*pile)->next)
		return (0);
	last = *pile;
	temp = last->next;
	while (last->next)
		last = last->next;
	last->next = *pile;
	*pile = temp;
	last->next->next = NULL;
	ft_putstr("ra\n");
	return (0);
}

int	reverse_rotate(t_pile **pile)
{
	t_pile	*temp;
	int		i;

	i = 0;
	if (!(*pile) || !(*pile)->next)
		return (0);
	temp = *pile;
	while ((*pile)->next)
	{
		*pile = (*pile)->next;
		i++;
	}
	(*pile)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	ft_putstr("rra\n");
	return (0);
}
