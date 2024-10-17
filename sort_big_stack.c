/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:29:05 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/17 22:05:32 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest_number(t_stack *b)
{
	int	i;
	int	max_number;

	i = 0;
	max_number = b->data[b->top];
	while (i < b->top)
	{
		if (b->data[i] > max_number)
			max_number = b->data[i];
		i++;
	}
	return (max_number);
}

int	get_smallest_number(t_stack *b)
{
	int	i;
	int	min_number;

	i = b->top;
	min_number = b->data[0];
	while (i > 0)
	{
		if (b->data[i] > min_number)
			min_number = b->data[i];
		i--;
	}
	return (min_number);
}

void	get_next_move(t_stack *a, t_stack *b)
{
	t_next_move next_move;
	int			max_number;
	int			min_number;

	max_number = get_biggest_number(b);
	min_number = get_smallest_number(b);

	next_move.position = a->top;
	next_move.num_moves = 0;
	if (a->data[next_move.position] > max_number)
	{
		if (b->data[b->top] == max_number)
		{
			next_move.num_moves++;
		}
		else
		{

		}
	}
}

void	big_stack(t_stack *a, t_stack *b, t_next_move *next_move)
{
	int			max_number;
	int			min_number;
	int			i;

	max_number = get_biggest_number(b);
	min_number = get_smallest_number(b);
	while (b->top < 1)
		pb(b, a);

	get_next_move(a, b);
}
