/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:49:23 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/22 22:15:44 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./libft/libftprintf.h"

typedef struct s_stack
{
	int	*data;
	int	top;
}		t_stack;

typedef struct s_move
{
	int	index;
	int	max_number;
	int	min_number;
	int	is_reverse_a;
	int	is_reverse_b;
	int	distance_ra;	// Creo que no hace falta
	int	distance_rra;

}		t_moves;


void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b);

int		wrong_input(int argc, char **argv);

int		is_sorted(t_stack *a);
int		is_sorted_reverse(t_stack *a);

void	short_list(t_stack *a);
void	merge_sort_stack(t_stack *a, t_stack *b, int size);
void	big_stack(t_stack *a, t_stack *b);

void	sort_big_stack(t_stack *a, t_stack *b);


#endif
