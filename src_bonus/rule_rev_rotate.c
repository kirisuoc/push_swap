/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:24:17 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/07 16:33:31 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Desplaza hacia abajo todos los elementos del stack A una posición, de forma
// que el último elemento se convierte en el primero.
void	rra_c(t_stack *a)
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
void	rrb_c(t_stack *b)
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

void	rrr_c(t_stack *a, t_stack *b)
{
	rra_c(a);
	rrb_c(b);
}
