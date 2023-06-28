/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_four.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:07:10 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/28 09:58:27 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*sort_list_of_four(t_pile *pile_a, t_pile *pile_b)
{
	if (sort_invers(&pile_a) == 0)
		verif_pile(&pile_a);
	else
		get_push_min(&pile_a, &pile_b, 1);
	pile_a = sort_list_of_three(pile_a);
	push_a(&pile_a, &pile_b);
	return (pile_a);
}
