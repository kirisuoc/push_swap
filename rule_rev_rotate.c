/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:24:17 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/13 23:35:58 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Desplaza hacia abajo todos los elementos del stack A una posición, de forma
// que el último elemento se convierte en el primero.
void	rra(t_stack *a)
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
}

// Desplaza hacia abajo todos los elementos del stack B una posición, de forma
// que el último elemento se convierte en el primero.
void	rrb(t_stack *b)
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
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
