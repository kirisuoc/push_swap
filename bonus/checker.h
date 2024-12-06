/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:25:06 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/06 16:25:37 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/libftprintf.h"

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
	int	distance_ra;
	int	distance_rra;
	int	is_reverse_a;

	int	distance_rb;	// Nuevo
	int	distance_rrb;	// Nuevo
	int	is_reverse_b;
	int	is_reverse_b_temp;

	int	rr;
	int	rrr;
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

#endif
