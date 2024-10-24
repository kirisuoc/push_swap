/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheaper_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:06:09 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/24 23:07:24 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	moves_to_top_a(t_stack *a, int num)
{
	int	current_moves;
	int	distance_ra;
	int	distance_rra;

	distance_ra = get_distance_ra(a, num);
	distance_rra = get_distance_rra(a, num);
	if (distance_ra <= distance_rra)
		current_moves = distance_ra;
	else
		current_moves = distance_rra;
	return (current_moves);
}

static int	moves_to_sort_in_b(t_stack *b, t_moves *next_move, int num)
{
	int	current_moves;
	int	distance_rb;
	int	distance_rrb;

	next_move->min_number = get_smallest_number(b);
	next_move->max_number = get_largest_number(b);
	distance_rb = get_distance_rb(b, next_move, num);
	distance_rrb = get_distance_rrb(b, next_move, num);
	if (distance_rb <= distance_rrb)
	{
		current_moves = distance_rb;
		next_move->is_reverse_b_temp = 0;
	}
	else
	{
		current_moves = distance_rrb;
		next_move->is_reverse_b_temp = 1;
	}
	return (current_moves);
}

void	get_cheaper_index(t_stack *a, t_stack *b, t_moves *next_move)
{
	int	moves;
	int	current_moves;
	int	i;

	next_move->is_reverse_a = 0;
	next_move->is_reverse_b = 0;
	moves = INT_MAX;
	i = 0;
	while (i <= a->top)
	{
		current_moves = 0;
		current_moves = moves_to_top_a(a, a->data[a->top - i]);
		current_moves += moves_to_sort_in_b(b, next_move, a->data[a->top - i]);
		current_moves++;
		if (current_moves < moves)
		{
			moves = current_moves;
			next_move->distance_ra = get_distance_ra(a, a->data[a->top - i]);
			next_move->distance_rra = get_distance_rra(a, a->data[a->top - i]);
			next_move->is_reverse_b = next_move->is_reverse_b_temp;
			if (next_move->distance_ra >= next_move->distance_rra)
				next_move->is_reverse_a = 1;
		}
		i++;
	}
}
