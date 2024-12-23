/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:50 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/08 12:12:50 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_position(t_stack *b, int max_number)
{
	int	max_pos;

	max_pos = 0;
	while (max_number != b->data[max_pos])
		max_pos++;
	return (max_pos);
}

void	final_sort_b(t_stack *b, t_moves *next_move)
{
	int	max_pos;

	max_pos = get_position(b, next_move->max_number);
	if (max_pos >= b->top / 2)
	{
		while (!is_sorted_reverse(b))
			rb(b, 1);
	}
	else
	{
		while (!is_sorted_reverse(b))
			rrb(b, 1);
	}
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	is_better_rr(t_moves *next_move)
{
	int	current_distance;
	int	other_dist_r;
	int	other_dist_rr;

	other_dist_r = ft_max(next_move->distance_ra, next_move->distance_rb);
	other_dist_rr = ft_max(next_move->distance_rra, next_move->distance_rrb);
	if (!next_move->is_reverse_a && next_move->is_reverse_b)
	{
		current_distance = next_move->distance_ra + next_move->distance_rrb;
		if ((other_dist_r < current_distance) && \
			other_dist_r <= other_dist_rr)
			next_move->is_reverse_b = 0;
		else if (other_dist_rr < current_distance)
			next_move->is_reverse_a = 1;
	}
	else if (next_move->is_reverse_a && !next_move->is_reverse_b)
	{
		current_distance = next_move->distance_rra + next_move->distance_rb;
		if ((other_dist_r < current_distance) && \
			other_dist_r <= other_dist_rr)
			next_move->is_reverse_a = 0;
		else if (other_dist_rr < current_distance)
			next_move->is_reverse_b = 1;
	}
}

void	make_common_rotations(t_stack *a, t_stack *b, t_moves *next_move)
{
	int	common_rotations;

	is_better_rr(next_move);
	common_rotations = get_common_rotations(next_move);
	if (next_move->rr)
	{
		while (common_rotations--)
		{
			rr(a, b);
			next_move->distance_ra --;
			next_move->distance_rb --;
		}
	}
	else if (next_move->rrr)
	{
		while (common_rotations--)
		{
			rrr(a, b);
			next_move->distance_rra --;
			next_move->distance_rrb --;
		}
	}
}
