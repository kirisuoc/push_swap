/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:29:05 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/18 21:16:55 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smallest_number(t_stack *a)
{
	int	i;
	int	smallest;

	i = a->top;
	smallest = a->data[0];
	while (i > 0)
	{
		if (a->data[i] < smallest)
			smallest = a->data[i];
		i--;
	}
	return (smallest);
}

static int	get_largest_number(t_stack *b)
{
	int i;
	int largest;

	i = b->top;
	largest = b->data[0];
	while (i > 0)
	{
		if (b->data[i] > largest)
			largest = b->data[i];
		i--;
	}
	return (largest);
}

static int	get_distance_r(t_stack *a, int	number)
{
	int	i;
	int	distance_ra;

	distance_ra = 0;
	i = a->top;
	while (i >= 0)
	{
		if (a->data[i] == number)
			break ;
		distance_ra++;
		i--;
	}
	return (distance_ra);
}

static int	get_distance_rr(t_stack *a, int number)
{
	int	i;
	int	distance_rra;

	distance_rra = 0;
	i = 0;
	while (i <= a->top)
	{
		if (a->data[i] == number)
		{
			distance_rra = i + 1;
			break ;
		}
		i++;
	}
	return (distance_rra);
}


static void	back_to_a(t_stack *a, t_stack *b)
{
	int	distance_rb;
	int	distance_rrb;
	int	max_number;

	while (b->top > -1)
	{
		max_number = get_largest_number(b);
		distance_rb = get_distance_r(b, max_number);
		distance_rrb = get_distance_rr(b, max_number);
		if (distance_rb <= distance_rrb)
		{
			while (distance_rb-- > 0)
				rb(b, 1);
		}
		else
		{
			while (distance_rrb-- > 0)
				rrb(b, 1);
		}
		pa(a, b);
	}
}

void	big_stack(t_stack *a, t_stack *b)
{
	int	distance_ra;
	int	distance_rra;
	int	min_number;

	while (a->top > -1)
	{
		min_number = get_smallest_number(a);
		distance_ra = get_distance_r(a, min_number);
		distance_rra = get_distance_rr(a, min_number);
		if (distance_ra <= distance_rra)
		{
			while (distance_ra-- >= 0)
			{
				if (a->data[a->top] >= min_number - 15 && a->data[a->top] <= min_number + 15)
					pb(b, a);
				ra(a, 1);
			}
		}
		else
		{
			while (distance_rra-- >= 0)
			{
				if (a->data[a->top] >= min_number - 15 && a->data[a->top] <= min_number + 15)
					pb(b, a);
				rra(a, 1);
			}
		}
	}
	back_to_a(a, b);
}
