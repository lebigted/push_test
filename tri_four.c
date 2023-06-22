/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_four.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:07:10 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/19 12:31:52 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*sort_list_of_four(t_pile *pile_a, t_pile *pile_b)
{
	int	i;

	i = 0;
	if (sort_invers(&pile_a) == 0)
		verif_pile(&pile_a);
	else
		get_push_min(&pile_a, &pile_b, 1);
	sort_list_of_three(pile_a);
	while (i < 2)
	{
		push_a(&pile_a, &pile_b);
		i++;
	}
	return (pile_a);
}
