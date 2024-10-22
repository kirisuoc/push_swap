/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:21:53 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/22 22:28:37 by erikcousill      ###   ########.fr       */
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

static int	get_distance_ra(t_stack *a, int	number)
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

static int	get_distance_rra(t_stack *a, int number)
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

static int	moves_to_top_a(t_stack *a, int num)
{
	int	current_moves;
	int	distance_ra;
	int	distance_rra;

	distance_ra = get_distance_ra(a, num);
	distance_rra = get_distance_rra(a, num);
	if (distance_ra <= distance_rra)
		current_moves = distance_ra;
	else
		current_moves = distance_rra;
	return (current_moves);
}

static int	get_distance_rb(t_stack *b, t_moves *next_move, int	number)
{
	int	i;
	int	distance_rb;

	distance_rb = 0;
	i = b->top;
	if (number > next_move->max_number || number < next_move->min_number)
	{
		while (b->data[b->top - i] != next_move->max_number)
		{
			distance_rb++;
			i--;
		}
	}
	else
	{
		while (!(number < b->data[b->top - i] && number > b->data[b->top - i - 1]))
		{
			distance_rb++;
			i--;
		}
	}
	return (distance_rb);
}

static int	get_distance_rrb(t_stack *b, t_moves *next_move, int	number)
{
	int	i;
	int	distance_rrb;

	distance_rrb = 0;
	i = 0;
	if (number > next_move->max_number || number < next_move->min_number)
	{
		while (b->data[i] != next_move->max_number)
		{
			distance_rrb++;
			i++;
		}
	}
	else
	{
		while (!(number < b->data[i + 1] && number > b->data[i]))
		{
			distance_rrb++;
			i++;
		}
		distance_rrb++;
	}
	return (distance_rrb);
}

static int	moves_to_sort_in_b(t_stack *b, t_moves *next_move, int num)
{
	int	current_moves;
	int	distance_rb;
	int	distance_rrb;

	next_move->min_number = get_smallest_number(b);
	next_move->max_number = get_largest_number(b);

	// Usar get_distance_rr para calcular moves por debajo

	distance_rb = get_distance_rb(b, next_move, num);
	distance_rrb = get_distance_rrb(b, next_move, num);
	if (distance_rb <= distance_rrb)
	{
		current_moves = distance_rb;
		next_move->is_reverse_b = 0;
	}
	else
	{
		current_moves = distance_rrb;
		next_move->is_reverse_b = 1;
	}
	return (current_moves);
}

static void	get_cheaper_index(t_stack *a, t_stack *b, t_moves *next_move)
{
	int	moves;			// Movimientos del número menos costoso (el que finalmente se moverá)
	int	current_moves;	// Movimientos del número que estamos analizando
	int	i;				// Índice que recorre todo el stack

	next_move->is_reverse_a = 0;
	moves = INT_MAX;	// Inicializamos en un número grande, para sobreescribirlo con el siguiente menor número de moves
	current_moves = 0;
	i = 0;
	while (i <= a->top)
	{
		current_moves = moves_to_top_a(a, a->data[a->top - i]);
		current_moves++;	// Por el movimiento a 'b' -> pb()
		current_moves = current_moves + moves_to_sort_in_b(b, next_move, a->data[a->top - i]);

		ft_printf("Moves: %d - Número: %d\n", current_moves, a->data[a->top - i]);
		if (current_moves < moves)
		{
			moves = current_moves;
			next_move->index = a->top - i;
			next_move->distance_ra = get_distance_ra(a, a->data[a->top - i]);
			next_move->distance_rra = get_distance_rra(a, a->data[a->top - i]);
			if (next_move->distance_ra > next_move->distance_rra)
				next_move->is_reverse_a = 1;
		}
		i++;
	}
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	t_moves next_move;

	next_move.index = -1;
	while (b->top < 1)
		pb(b, a);

	// DE MOMENTO PROBAMOS NO ORDENÁNDOLOS			if (b->data[b->top] < b->data[b->top - 1])
	//													sb(b, 1);

	get_cheaper_index(a, b, &next_move);
	ft_printf("next_move.index: %d\n", next_move.index);
/* 	while (a->top > -1)
	{
		// Función que calcula el costo

		// Función que lleva a cambio los movimientos
	} */
	while (b->top > -1)
		pa(a, b);
}
