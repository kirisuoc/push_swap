/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheaper_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:06:09 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/23 21:40:09 by ecousill         ###   ########.fr       */
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
	int	i;
	int	largest;

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

static int	get_distance_rb(t_stack *b, t_moves *next_move, int number)
{
	int	i;
	int	distance_rb;

	distance_rb = 0;
	i = b->top;
	//ft_printf("Number: %d\n", number);
	if (number > next_move->max_number || number < next_move->min_number)
	{
		//ft_printf("b->data[i]: %d\n", b->data[i]);
		while (b->data[i] != next_move->max_number)
		{
			distance_rb++;
			i--;
		}
	}
	else
	{
		if (number > b->data[b->top] && number < b->data[0])
		{
			//ft_printf("DISTANCE_RB: %d\n", distance_rb);
			return (distance_rb);
		}
		while (!(number < b->data[i] && number > b->data[i - 1]))
		{
			distance_rb++;
			i--;
		}
		distance_rb++;
	}
	//ft_printf("DISTANCE_RB: %d\n", distance_rb);
	return (distance_rb);
}

static int	get_distance_rrb(t_stack *b, t_moves *next_move, int number)
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
		{
			//ft_printf("DISTANCE_RRB: %d\n", distance_rrb);
			return (distance_rrb);
		}
		while (!(number < b->data[i + 1] && number > b->data[i]))
		{
			distance_rrb++;
			i++;
		}
		distance_rrb++;
	}
	//ft_printf("DISTANCE_RRB: %d\n", distance_rrb);
	return (distance_rrb);
}

static int	get_distance_ra(t_stack *a, int number)
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

static int	moves_to_sort_in_b(t_stack *b, t_moves *next_move, int num)
{
	int	current_moves;
	int	distance_rb;
	int	distance_rrb;

	next_move->min_number = get_smallest_number(b);
	next_move->max_number = get_largest_number(b);
	distance_rb = get_distance_rb(b, next_move, num);
	distance_rrb = get_distance_rrb(b, next_move, num);
	if (distance_rb <= distance_rrb)
	{
		current_moves = distance_rb;
		next_move->is_reverse_b_temp = 0;
	}
	else
	{
		current_moves = distance_rrb;
		next_move->is_reverse_b_temp = 1;
	}
	return (current_moves);
}

void	get_cheaper_index(t_stack *a, t_stack *b, t_moves *next_move)
{
	int	moves;
	int	current_moves;
	int	i;

	next_move->is_reverse_a = 0;
	next_move->is_reverse_b = 0;
	moves = INT_MAX; // Inicializamos en un número grande, para sobreescribirlo con el siguiente menor número de moves
	current_moves = 0;
	i = 0;
	while (i <= a->top)
	{
		current_moves = 0;
		current_moves = moves_to_top_a(a, a->data[a->top - i]);
		current_moves += moves_to_sort_in_b(b, next_move, a->data[a->top - i]);
		current_moves++; // Por el movimiento a 'b' -> pb()		ft_printf("--Moves: %d - Número: %d\n", current_moves, a->data[a->top - i]);
		//ft_printf("--Moves: %d - Número: %d\n", current_moves, a->data[a->top - i]);
		if (current_moves < moves)
		{
			moves = current_moves;
			next_move->index = a->top - i;
			next_move->distance_ra = get_distance_ra(a, a->data[a->top - i]);
			next_move->distance_rra = get_distance_rra(a, a->data[a->top - i]);
			next_move->is_reverse_b = next_move->is_reverse_b_temp;
			//ft_printf(GREEN"next_move->is_reverse_b: %d\n"RESET, next_move->is_reverse_b);

			if (next_move->distance_ra >= next_move->distance_rra)
				next_move->is_reverse_a = 1;
		}
		i++;
	}
	//ft_printf("Moves: %d - Número: %d\n", moves, a->data[next_move->index]);
}
