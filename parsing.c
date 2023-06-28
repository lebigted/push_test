/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:54:00 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/28 13:23:07 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_errorparse(char *mess)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(mess, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int	check_duplicate(long int *pile, int size, int nb)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (pile[i] == nb)
			exit_errorparse("error : duplicates values\n");
		i++;
	}
	return (1);
}

static int	overflow_check(long result, char c, int sign)
{
	if (result > (INT_MAX - (c - '0')) / 10)
	{
		if (sign == 1)
			exit_errorparse("error : overint\n");
		else if (result > (-(INT_MIN + (c - '0')) / 10) + 1)
			exit_errorparse("error : underint\n");
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long	result;
	int		sign;
	size_t	i;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
		i++;
	}
	while (str[i])
	{
		if (!isdigit(str[i]))
			exit_errorparse("error : unexpected value\n");
		overflow_check(result, str[i], sign);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)(result * sign));
}

void	add_to_pile(t_pile **a, int c)
{
	t_pile	*last;
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return ;
	new->next = NULL;
	new->value = c;
	if (!*a)
	{
		*a = new;
		return ;
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = new;
}
