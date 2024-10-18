/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:25:04 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/18 17:44:27 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_list(t_stack *a)
{
	while (!is_sorted(a))
	{
		if (a->data[a->top] > a->data[a->top - 1])
			sa(a, 1);
		else
			rra(a, 1);
	}
}
