/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:24:01 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/07 16:40:20 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Desplaza hacia arriba todos los elementos del stack A una posición, de forma
// que el primer elemento se convierte en el último.
void	ra_c(t_stack *a)
{
	int	temp;
	int	i;

	if (a->top > 0)
	{
		i = a->top;
		temp = a->data[a->top];
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[0] = temp;
	}
}

// Desplaza hacia arriba todos los elementos del stack B una posición, de forma
// que el primer elemento se convierte en el último.
void	rb_c(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top > 0)
	{
		i = b->top;
		temp = b->data[b->top];
		while (i > 0)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[0] = temp;
	}
}

void	rr_c(t_stack *a, t_stack *b)
{
	ra_c(a);
	rb_c(b);
}
