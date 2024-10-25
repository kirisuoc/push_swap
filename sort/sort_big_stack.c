/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:21:53 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/25 13:19:31 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	move_to_correct_position_in_b(t_stack *a, t_stack *b,
	t_moves *next_move)
{
	int	i;

	if (a->data[a->top] > b->data[b->top] && a->data[a->top] < b->data[0])
	{
		pb(b, a);
		return (1);
	}
	else if (!next_move->is_reverse_b)
	{
		i = b->top;
		while (!(a->data[a->top] < b->data[i]
				&& a->data[a->top] > b->data[i - 1]))
			rb(b, 1);
		rb(b, 1);
	}
	else
	{
		i = 0;
		while (!(a->data[a->top] < b->data[i + 1]
				&& a->data[a->top] > b->data[i]))
			rrb(b, 1);
		rrb(b, 1);
	}
	return (0);
}

static void	make_move(t_stack *a, t_stack *b, t_moves *next_move)
{
	if (!next_move->is_reverse_a)
		while (next_move->distance_ra-- > 0)
			ra(a, 1);
	else
		while (next_move->distance_rra-- > 0)
			rra(a, 1);
	if (a->data[a->top] > next_move->max_number
		|| a->data[a->top] < next_move->min_number)
	{
		if (!next_move->is_reverse_b)
			while (b->data[b->top] != next_move->max_number)
				rb(b, 1);
		else
			while (b->data[b->top] != next_move->max_number)
				rrb(b, 1);
	}
	else
	{
		if (move_to_correct_position_in_b(a, b, next_move))
			return ;
	}
	pb(b, a);
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	t_moves	next_move;

	next_move.index = -1;
	while (b->top < 1)
		pb(b, a);
	while (a->top > -1)
	{
		get_cheaper_index(a, b, &next_move);
		make_move(a, b, &next_move);
	}
	final_sort_b(b, &next_move);
	while (b->top > -1)
		pa(a, b);
}
