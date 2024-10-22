/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:21:53 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/22 15:48:13 by ecousill         ###   ########.fr       */
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

int	moves_to_top_a(t_stack *a, t_moves *next_move)
{
	int	i;
	int	current_moves;

	i = 0;
	while (i++ <= a->top)
	{
		next_move->distance_ra = get_distance_r(a, a->data[a->top - i]);
		next_move->distance_rra = get_distance_rr(a, a->data[a->top - i]);
		if (next_move->distance_ra <= next_move->distance_rra)
			current_moves = next_move->distance_ra;
		else
			current_moves = next_move->distance_rra;
	}
	return (current_moves);
}

void	get_cheaper_index(t_stack *a, t_stack *b, t_moves *next_move)
{
	int	moves;			// Movimientos del número menos costoso (el que finalmente se moverá)
	int	current_moves	// Movimientos del número que estamos analizando
	int	i;
	int	j;

}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	t_moves next_move;

	next_move.index = -1;
	while (b->top < 1)
		pb(b, a);

	// DE MOMENTO PROBAMOS NO ORDENÁNDOLOS			if (b->data[b->top] < b->data[b->top - 1])
	//													sb(b, 1);

	while (a->top > -1)
	{
		// Función que calcula el costo

		// Función que lleva a cambio los movimientos
	}
	while (b->top > -1)
		pa(a, b);
}
