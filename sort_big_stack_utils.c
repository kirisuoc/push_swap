/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:50 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/24 17:31:38 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *b, int max_number)
{
	int	max_pos;

	max_pos = 0;
	while (max_number != b->data[max_pos])
		max_pos++;
	return (max_pos);
}


void final_sort_b(t_stack *b, t_moves *next_move)
{
    int max_pos;

	max_pos = get_position(b, next_move->max_number);

    // Si el valor máximo está en la primera mitad del stack, es más eficiente usar 'rb'
    if (max_pos >= b->top / 2)
    {
        // Rotar hacia abajo hasta que esté ordenado en orden descendente
        while (!is_sorted_reverse(b))
            rb(b, 1);
    }
    else
    {
        // Si el valor máximo está en la segunda mitad, rotar hacia arriba con 'rrb'
        while (!is_sorted_reverse(b))
            rrb(b, 1);
    }
}
