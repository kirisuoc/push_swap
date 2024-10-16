/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:24:17 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/16 13:28:32 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Desplaza hacia abajo todos los elementos del stack A una posición, de forma
// que el último elemento se convierte en el primero.
void	rra(t_stack *a, int print)
{
	int	temp;
	int	i;

	if (a->top > 0)
	{
		i = 0;
		temp = a->data[0];
		while (i < a->top)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->data[a->top] = temp;
	}
	if (print)
		write(1, "rra\n", 4);
}

// Desplaza hacia abajo todos los elementos del stack B una posición, de forma
// que el último elemento se convierte en el primero.
void	rrb(t_stack *b, int print)
{
	int	temp;
	int	i;

	if (b->top > 0)
	{
		i = 0;
		temp = b->data[0];
		while (i < b->top)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->data[b->top] = temp;
	}
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
