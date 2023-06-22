/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:47:33 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/19 09:48:15 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*stock;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	stock = malloc(count * size);
	if (!stock)
		return (0);
	ft_bzero(stock, (count * size));
	return (stock);
}
