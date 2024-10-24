/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:25:04 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 13:21:04 by ecousill         ###   ########.fr       */
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
