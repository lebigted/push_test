/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:12:13 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/28 13:39:58 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*info_main(int argc, char **argv)
{
	t_pile	*pile;

	if (argc == 2)
		pile = create_for_one(argv[1]);
	else
		pile = create_pile_from_arguments(argc, argv);
	pile->set_index = s_index(pile);
	return (pile);
}

int	is_sort(t_pile *pile_a)
{
	if (!pile_a || !pile_a->next)
		return (1);
	if (pile_a->value > pile_a->next->value)
		return (0);
	return (is_sort(pile_a->next));
}

void	free_full_pile(t_pile *pile)
{
	t_pile	*tmp;

	tmp = 0;
	while (pile != 0)
	{
		tmp = pile;
		pile = tmp->next;
		free(tmp);
	}
}

void	check(int i, t_pile *pile_a, t_pile *pile_b)
{
	t_pile	*p;

	if (is_sort(pile_a))
		return ;
	if (i == 3)
	{
		p = sort_list_of_three(pile_a);
		free_full_pile(p);
	}
	else if (i == 4)
	{
		p = sort_list_of_four(pile_a, pile_b);
		free_full_pile(p);
	}
	else if (i == 5)
	{
		p = sort_list_of_five(pile_a, pile_b);
		free_full_pile(p);
	}
	else
	{
		p = radix_sort(pile_a, pile_b);
		free_full_pile(p);
	}
}

int	main(int argc, char **argv)
{
	t_pile		*pile_a;
	t_pile		*pile_b;
	t_pile		*pile;
	long int	i;

	i = 0;
	pile_a = NULL;
	pile_b = NULL;
	if (argc == 1)
		return (0);
	pile = info_main(argc, argv);
	while (pile->size > i)
	{
		add_to_pile(&pile_a, pile->set_index[i]);
		i++;
	}
	check(i, pile_a, pile_b);
	//system("leaks push_swap");
	return (0);
}
