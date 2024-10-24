/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:50 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/24 23:07:30 by erikcousill      ###   ########.fr       */
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
