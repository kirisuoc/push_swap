/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:06:44 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 10:46:20 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	fill_stack(t_stack *a, int argc, char **argv)
{
	int i;

	i = 1;
	a->top = argc - 2;
	while (i < argc)
	{
		a->data[i - 1] = ft_atoi(argv[argc - i]);
		i++;
	}
}


static void	sort_list(t_stack *a, t_stack *b)
{
 	if (a->top + 1 == 3)
	{
		short_list(a);
	}
	else
		sort_big_stack(a, b);
}



int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc == 1)
		return (1);
	if (wrong_input(argc, argv))
		return (1);
	a.data = ft_calloc((argc - 1), sizeof(int));
	b.data = ft_calloc((argc - 1), sizeof(int));
	if (!a.data || !b.data)
		return (1);
	fill_stack(&a, argc, argv);
	if (is_sorted(&a))
	{
		free(a.data);
		free(b.data);
		ft_printf("Ordenado");
		return (0);
	}
	b.top = -1;

	sort_list(&a, &b);

	free(a.data);
	free(b.data);
	return (0);
}
