/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:25:04 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/17 21:25:47 by erikcousill      ###   ########.fr       */
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

void	up_to_5(t_stack *a, t_stack *b)
{
	while (a->top > 2)
		pb(b, a);
	short_list(a);
	while (b->top > -1)
	{
		if (b->data[b->top] < a->data[a->top])
			pa(a, b);
		else if (b->data[b->top] > a->data[0])
		{
			pa(a, b);
			ra(a, 1);
		}
		else
		{
			while (b->data[b->top] > a->data[a->top] || b->data[b->top] < a->data[0])
				ra(a, 1);
			pa(a, b);

		}
		while (!is_sorted(a))
			rra(a, 1);
	}
}
