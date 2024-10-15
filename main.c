/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:06:44 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/15 19:06:15 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libft/libftprintf.h"
#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->data[a->top - i] > a->data[a->top - i - 1])
			return (0);
		i++;
	}
	return (1);
}


void	fill_stack(t_stack *a, int argc, char **argv)
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

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc == 1)
		return (1);
	if (wrong_input(argc, argv))
		return (1);

	a.data = malloc((argc - 1) * sizeof(int));
	b.data = malloc((argc - 1) * sizeof(int));
	if (!a.data || !b.data)
		return (1);

	fill_stack(&a, argc, argv);

	if (is_sorted(&a))
	{
		free(a.data);
		free(b.data);
		return (0);
	}

							// Imprimir el contenido del stack desde el top hasta el bottom
							for (int j = a.top; j >= 0; j--) { // Cambiado para imprimir desde el top
								ft_printf("%d\n", a.data[j]);
							}

	free(a.data);
	free(b.data);
	return (0);
}

