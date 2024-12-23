/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:49:23 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/08 12:19:46 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int	distance_rb;
	int	distance_rrb;
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

int		wrong_input(int argc, char **argv);
int		check_repeated_int(int count, int *numbers);
int		is_dup_numbers(int count, char **argv);
int		is_valid_integer(const char *str);
int		is_in_int_range(const char *str);

int		is_sorted(t_stack *a);
int		is_sorted_reverse(t_stack *a);
int		get_smallest_number(t_stack *a);
int		get_largest_number(t_stack *b);
void	free_list(char **list);

void	short_list(t_stack *a);
void	medium_list(t_stack *a, t_stack *b);
void	sort_big_stack(t_stack *a, t_stack *b);
int		get_common_rotations(t_moves *next_move);

int		get_position(t_stack *b, int max_number);
void	final_sort_b(t_stack *b, t_moves *next_move);
int		ft_max(int a, int b);
void	is_better_rr(t_moves *next_move);
void	make_common_rotations(t_stack *a, t_stack *b, t_moves *next_move);

void	get_cheaper_index(t_stack *a, t_stack *b, t_moves *next_move);

int		get_distance_rb(t_stack *b, t_moves *next_move, int number);
int		get_distance_rrb(t_stack *b, t_moves *next_move, int number);
int		get_distance_ra(t_stack *a, int number);
int		get_distance_rra(t_stack *a, int number);

#endif
