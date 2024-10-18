/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:29:05 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/18 18:53:16 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smallest_number(t_stack *a)
{
	int	i;
	int	min_number;

	i = a->top;
	min_number = a->data[0];
	while (i >= 0)
	{
		if (a->data[i] < min_number)
			min_number = a->data[i];
		i--;
	}
	return (min_number);
}

static int	get_distance_ra(t_stack *a)
{
	int	i;
	int	min_number;
	int	distance_ra;

	min_number = get_smallest_number(a);
	distance_ra = 0;
	i = a->top;
	while (i >= 0)
	{
		if (a->data[i] == min_number)
			break ;
		distance_ra++;
		i--;
	}
	return (distance_ra);
}

static int	get_distance_rra(t_stack *a)
{
	int	i;
	int	min_number;
	int	distance_rra;

	min_number = get_smallest_number(a);
	distance_rra = 0;
	i = 0;
	while (i <= a->top)
	{
		if (a->data[i] == min_number)
		{
			distance_rra = i + 1;
			break ;
		}
		i++;
	}
	return (distance_rra);
}

void	big_stack(t_stack *a, t_stack *b)
{
	int	distance_ra;
	int	distance_rra;

	while (a->top > 2)
	{
		distance_ra = get_distance_ra(a);
		distance_rra = get_distance_rra(a);
		if (distance_ra <= distance_rra)
		{
			while (distance_ra-- > 0)
				ra(a, 1);
		}
		else
		{
			while (distance_rra-- > 0)
				rra(a, 1);
		}
		pb(b, a);
	}
	short_list(a);
	while (b->top > -1)
		pa(a, b);
}
