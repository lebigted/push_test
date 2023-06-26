/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:06:34 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/26 05:51:53 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*create_pile_from_arguments(int argc, char **argv)
{
	int		i;
	t_pile	*pile;

	pile = NULL;
	i = 1;
	pile = malloc(sizeof(t_pile));
	if (pile == NULL)
		return (NULL);
	pile->size = argc - 1;
	pile->tab = malloc(sizeof(long int) * (argc - 1));
	if (pile->tab == NULL)
		return (NULL);
	while (i < argc)
	{
		pile->tab[i - 1] = ft_atoi(argv[i]);
		check_duplicate(pile->tab, i, pile->tab[i - 1]);
		i++;
	}
	return (pile);
}

void	free_utils(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

t_pile	*create_for_one(char *num)
{
	char	**ar;
	t_pile	*pile;
	int		i;

	i = 0;
	ar = ft_split(num, ' ');
	if (ar == NULL)
		return (NULL);
	pile = malloc(sizeof(*pile));
	if (pile == NULL)
		return (NULL);
	pile->size = 0;
	while (ar[pile->size])
		pile->size++;
	pile->tab = malloc(sizeof(long int) * pile->size);
	if (pile->tab == NULL)
		return (NULL);
	while (ar[i])
	{
		pile->tab[i] = ft_atoi(ar[i]);
		check_duplicate(pile->tab, i + 1, pile->tab[i]);
		i++;
	}
	free_utils(ar);
	return (pile);
}
