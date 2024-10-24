/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:25:04 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 16:54:32 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_list(t_stack *a)
{
	while (!is_sorted(a))
	{
		if (a->data[a->top] > a->data[a->top - 1])
			sa(a, 1);
		else
			rra(a, 1);
	}
}
/* void short_list(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->data[a->top];
	mid = a->data[a->top - 1];
	bottom = a->data[a->top - 2];
	if (top > mid && mid > bottom) // Caso: 3 2 1
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if (top > bottom && bottom > mid) // Caso: 3 1 2
		ra(a, 1);
	else if (mid > top && top > bottom) // Caso: 2 3 1
		rra(a, 1);
	else if (mid > bottom && bottom > top)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (bottom > top && top > mid) // Caso: 1 3 2
		sa(a, 1);
} */

void	medium_list(t_stack *a, t_stack *b)
{
	while (a->top > 2)
		pb(b, a);
	short_list(a);
	while (b->top > -1)
	{
		if (b->data[b->top] > get_largest_number(a)
			|| b->data[b->top] < get_smallest_number(a))
			while (a->data[a->top] != get_smallest_number(a))
				ra(a, 1);
		else
		{
			while (!(a->data[a->top] > b->data[b->top]
					&& a->data[0] < b->data[b->top]))
				ra(a, 1);
		}
		pa(a, b);
	}
	while (!is_sorted(a))
	{
		if (get_largest_number(a) == a->data[1]
			|| get_largest_number(a) == a->data[2])
			rra(a, 1);
		else
			ra(a, 1);
	}
}
