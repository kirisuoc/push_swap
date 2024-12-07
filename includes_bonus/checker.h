/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:25:06 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/07 14:14:23 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/libftprintf.h"
# include "../gnl/get_next_line.h"

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

// wrong_input.c
int		wrong_input(int argc, char **argv);

// wrong_input_utils.c
int		is_valid_integer(const char *str);
int		is_in_int_range(const char *str);
int		is_dup_numbers(int count, char **argv);
int		check_repeated_int(int count, int *numbers);

// free.c
void	free_resources(int *numbers, char **split_lst);
void	free_list(char **list);

#endif
