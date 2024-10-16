/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:24:01 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/16 16:33:56 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Desplaza hacia arriba todos los elementos del stack A una posición, de forma
// que el primer elemento se convierte en el último.
void	ra(t_stack *a, int print)
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
	if (print)
		write(1, "ra\n", 3);

}

// Desplaza hacia arriba todos los elementos del stack B una posición, de forma
// que el primer elemento se convierte en el último.
void	rb(t_stack *b, int print)
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
	if (print)
		write(1, "rb\n", 3);

}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
