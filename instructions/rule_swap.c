/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:23:32 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 23:08:00 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Intercambia los dos primeros elementos del stack A. No hace nada si hay
// uno o menos elementos.
void	sa(t_stack *a, int print)
{
	int	temp;

	if (a->top > 0)
	{
		temp = a->data[a->top];
		a->data[a->top] = a->data[a->top - 1];
		a->data[a->top - 1] = temp;
	}
	if (print)
		write(1, "sa\n", 3);
}

// Intercambia los dos primeros elementos del stack B. No hace nada si hay
// uno o menos elementos.
void	sb(t_stack *b, int print)
{
	int	temp;

	if (b->top > 0)
	{
		temp = b->data[b->top];
		b->data[b->top] = b->data[b->top - 1];
		b->data[b->top - 1] = temp;
	}
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
