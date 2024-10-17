/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:49:23 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/17 21:48:19 by erikcousill      ###   ########.fr       */
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
	int	*data;	// Array de enteros que almacena los elementos del stack
	int	top;	// Índice del último elemento del stack (similar a puntero)
}		t_stack;

typedef struct s_next_move
{
	int	position;
	int	num_moves;
}		t_next_move;


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

void	short_list(t_stack *a);
void	up_to_5(t_stack *a, t_stack *b);


#endif
