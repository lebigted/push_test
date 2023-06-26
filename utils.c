/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 06:42:46 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/26 08:37:44 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	free_pile(char **ar)
// {
// 	int	i;

// 	i = 0;
// 	while (ar[i])
// 	{
// 		free(ar[i]);
// 		i++;
// 	}
// 	free(ar);
// }

// t_pile	*get_last_elem(t_pile *pile)
// {
// 	t_pile	*current_elem;

// 	current_elem = pile;
// 	if (current_elem == NULL)
// 		return (NULL);
// 	while (current_elem->next)
// 	{
// 		current_elem = current_elem->next;
// 	}
// 	return (current_elem);
// }

// t_pile	*get_last_elem_before(t_pile *pile)
// {
// 	t_pile	*current_elem;

// 	current_elem = pile;
// 	if (current_elem == NULL || current_elem->next == NULL)
// 		return (NULL);
// 	while (current_elem->next->next)
// 	{
// 		current_elem = current_elem->next;
// 	}
// 	return (current_elem);
// }
