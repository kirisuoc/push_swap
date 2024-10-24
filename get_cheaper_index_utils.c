/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheaper_index_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:34:56 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/24 13:36:10 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance_rb(t_stack *b, t_moves *next_move, int number)
{
	int	i;
	int	distance_rb;

	distance_rb = 0;
	i = b->top;
	if (number > next_move->max_number || number < next_move->min_number)
	{
		while (b->data[i] != next_move->max_number)
		{
			distance_rb++;
			i--;
		}
	}
	else
	{
		if (number > b->data[b->top] && number < b->data[0])
			return (distance_rb);
		while (!(number < b->data[i] && number > b->data[i - 1]))
		{
			distance_rb++;
			i--;
		}
		distance_rb++;
	}
	return (distance_rb);
}

int	get_distance_rrb(t_stack *b, t_moves *next_move, int number)
{
	int	i;
	int	distance_rrb;

	distance_rrb = 0;
	i = 0;
	if (number > next_move->max_number || number < next_move->min_number)
	{
		while (b->data[i++] != next_move->max_number)
			distance_rrb++;
		distance_rrb++;
	}
	else
	{
		if (number > b->data[b->top] && number < b->data[0])
			return (distance_rrb);
		while (!(number < b->data[i + 1] && number > b->data[i]))
		{
			distance_rrb++;
			i++;
		}
		distance_rrb++;
	}
	return (distance_rrb);
}

int	get_distance_ra(t_stack *a, int number)
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

int	get_distance_rra(t_stack *a, int number)
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
