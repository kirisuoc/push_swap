/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:29:05 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/22 15:19:46 by ecousill         ###   ########.fr       */
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

void	optimizing(t_stack *a, t_stack *b)
{
	if (a->data[a->top] > a->data[a->top - 1] && b->data[b->top] < b->data[b->top - 1])
	{
		ss(a, b);
	}
}

/*static void	back_to_a(t_stack *a, t_stack *b)
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
				optimizing(a, b);
				if (a->data[a->top] >= min_number && a->data[a->top] <= min_number)
					pb(b, a);
				ra(a, 1);
			}
		}
		else
		{
			while (distance_rra-- >= 0)
			{
				optimizing(a, b);
				if (a->data[a->top] >= min_number && a->data[a->top] <= min_number)
					pb(b, a);
				rra(a, 1);
			}
		}
	}
	back_to_a(a, b);
}
 */

/* void	fill_move(t_moves *next_move, t_stack *a, t_stack *b)
{
	next_move->min_number = get_smallest_number(b);
	next_move->max_number = get_largest_number(b);
	next_move->num_moves = 1;
	next_move->index_num_to_move = a->top;
} */

/* int	count_moves(t_stack *a, t_stack *b, t_moves *next_move, int i) // int i ?? Índice del número que estamos comprobando
{
	int	moves; // Cambiar moves a next_move->num_moves ??

	moves = 0;
	if (a->data[a->top - i] > next_move->max_number)
	{
		if (b->data[b->top] == next_move->max_number)
		{
			// Ordenar lista y contar moves ?? Para saber moves reales de poner max arriba (o abajo?)
			moves = 1 + i; // Sumamos i por que es la posición del número en 'a' y tendremos que subirlo a top
			return (moves);
		}
	}
	else if (a->data[a->top - i] < next_move->max_number)
	{
		if (b->data[b->top] == next_move->max_number)
		{
			// Ordenar lista y contar moves ?? Para saber moves reales de poner min arriba
			moves = 1 + i; // Sumamos i por que es la posición del número en 'a' y tendremos que subirlo a top
			return (moves);
		}
	}
	else // Este número no es ni max ni min. Hay que buscar en 'b' su posición (entre su anterior y posterior)
	{
		// Count será lo que cueste subirlo en 'a' + lo que cueste bajarlo en 'b' a su posición
		// Si la lista está ordenada, solo hay que encontrar el número que es mayor y el de debajo sea menor
		// Bucle desde b->top hasta encontrar que b->data[j] > NÚMERO && b->data[j - 1] < NÚMERO
		int	j = 0;
		while (j < b->top)
		{
			if (b->data[b->top - j] > a->data[a->top - i] && b->data[b->top - j - 1] < a->data[a->top - i])
			{
				moves = 1 + i + j;
				next_move->index = a->top - i; // ??
				return (moves);
			}
			j++;
		}
	}
}
 */
// Vamos cogiendo el resultado de count_moves y decidimos qué número vamos a mover. Solo lo actualiamos si el
// número es más barato que el que tenemos actualmente
static void	make_move(t_stack *a, t_stack *b, t_moves *next_move)
{
	int j;

	if (!next_move->is_reverse)
	{
		while (next_move->index < a->top && a->top != 0)
		{
			ra(a, 1);
			next_move->index++;
		}
	}
	else if (next_move->is_reverse && a->top != 0)
	{
		while (next_move->index < 0)
		{
			rra(a, 1);
			next_move->index++;
		}
	}
	if (a->data[a->top] > next_move->max_number || a->data[a->top] < next_move->min_number)
	{
		if (b->data[b->top] == next_move->max_number)
		{
			pb(b, a);
		}
		else if (b->data[b->top] == next_move->min_number)
		{
			pb(b, a);
			rb(b, 1);
		}
	}
	else
	{
		j = 0;
		while (j < b->top)
		{
			if (b->data[b->top] > a->data[a->top] && (b->data[b->top - 1] < a->data[a->top]))
			{
				rb(b, 1);
				break;
			}

			rb(b, 1);
			j++;
		}
		pb(b, a);

		/* while () */

	}
}

void	get_cheaper_index(t_stack *a, t_stack *b, t_moves *next_move)
{
	int	moves;
	int	current_moves;
	int	i;
	int j;
	int	distance_ra_temp;
	int	distance_rra_temp;


	next_move->min_number = get_smallest_number(b);
	next_move->max_number = get_largest_number(b);
	moves = INT_MAX;
	current_moves = 0;
	i = 0;
	while (i <= a->top)
	{
		distance_ra_temp = get_distance_r(a, a->data[a->top - i]);
		distance_rra_temp = get_distance_rr(a, a->data[a->top - i]);
		if (distance_ra_temp <= distance_rra_temp)
		{
			current_moves = distance_ra_temp;
		}
		else
		{
			current_moves = distance_rra_temp;
		}
		if (a->data[a->top - i] > next_move->max_number || a->data[a->top - i] < next_move->min_number)
		{
			if (b->data[b->top] == next_move->max_number)
			{
				current_moves++;
			}
			else if (b->data[b->top] == next_move->min_number)
			{
				current_moves = current_moves + 2;
			}
		}
		else
		{
			j = 0;
			while (j < b->top)
			{
				if (b->data[b->top - j] > a->data[a->top - i] && b->data[b->top - j - 1] < a->data[a->top - i])
				{
					current_moves = 1 + i + j;
				}
				j++;
			}
		}
		if (current_moves < moves)
		{
			moves = current_moves;
			next_move->index = a->top - i;
			next_move->distance_ra = distance_ra_temp;
			next_move->distance_rra = distance_rra_temp;
			if (distance_ra_temp < distance_rra_temp)
			{
				next_move->is_reverse = 0;
			}
			else
			{
				next_move->is_reverse = 1;
			}
		}
		i++;
	}
}

void	sort_big_list(t_stack *a, t_stack *b)
{
	t_moves next_move;

	next_move.index = -1;

	while (b->top < 1)
	{
		pb(b, a);
	}
	if (b->data[b->top] < b->data[b->top - 1])
		sb(b, 1);
	while (a->top > -1)
	{

		get_cheaper_index(a, b, &next_move);
		make_move(a, b, &next_move);

		if (b->data[b->top] < b->data[b->top - 1])
			rb(b, 1);
	}

  	/*while (!is_sorted_reverse(b))
		rrb(b, 1);*/
  	while (b->top > -1)
	{
		pa(a, b);
	}
}

