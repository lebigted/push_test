/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:57:32 by ltestard          #+#    #+#             */
/*   Updated: 2023/06/28 11:36:17 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <ctype.h>

typedef struct s_pile
{
	int				value;
	long int		*tab;
	long int		*set_index;
	int				size;
	struct s_pile	*next;
}t_pile;

int			swap(t_pile **pile_a);
int			push_a(t_pile **pile_a, t_pile **pile_b);
int			push_b(t_pile **pile_a, t_pile **pile_b);
int			rotate(t_pile **pile_a);
int			reverse_rotate(t_pile **pile_a);
int			check_case(t_pile *pile);
int			ft_atoi(char *str);
int			ft_isdigit(int c);
int			is_sorted(t_pile *stack);
int			ft_pilesize(t_pile *pile);
int			check_tri(t_pile **pile);
int			check_duplicate(long int *pile, int size, int nb);
int			sort_invers(t_pile **pile_a);
int			is_sort(t_pile *pile_a);
int			pile_size(t_pile *pile);

size_t		ft_strlen(const char *str);

long int	*s_index(t_pile *pile);

char		**ft_split(char const *s, char c);

t_pile		*sort_list_of_three(t_pile *pile_a);
t_pile		*sort_list_of_four(t_pile *pile_a, t_pile *pile_b);
t_pile		*sort_list_of_five(t_pile *pile_a, t_pile *pile_b);
t_pile		*radix_sort(t_pile *pile_a, t_pile *pile_b);
t_pile		*create_pile_from_arguments(int argc, char **argv);
t_pile		*create_for_one(char *num);

void		verif_pile(t_pile **pile_a);
void		get_push_min(t_pile **pile_a, t_pile **pile_b, int n);
void		exit_errorparse(char *mess);
void		get_max(t_pile *pile_a, int *maxnum, int *maxbit);
void		add_to_pile(t_pile **a, int c);
void		ft_putstr(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		free_utils(char **ar);
#endif
