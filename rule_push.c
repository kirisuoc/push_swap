/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:23:45 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/15 23:29:33 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Toma el primer elemento del stack B y lo pone el primero en el stack A.
// No hace nada si B está vacío.
void	pa(t_stack *a, t_stack *b)
{
	if (b->top >= 0)
	{
		a->data[a->top + 1] = b->data[b->top];
		a->top++;
		b->top--;
	}
	write(1, "pa\n", 3);
}

// Toma el primer elemento del stack A y lo pone el primero en el stack B.
// No hace nada si A está vacío.
void	pb(t_stack *b, t_stack *a)
{
	if (a->top >= 0)
	{
		b->data[b->top + 1] = a->data[a->top];
		b->top++;
		a->top--;
	}
	write(1, "pb\n", 3);
}
