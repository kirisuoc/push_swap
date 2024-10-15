/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:06:44 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/15 14:04:29 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libft/libftprintf.h"
#include "push_swap.h"

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

	a.data = malloc((argc - 1) * sizeof(int));
	if (!a.data)
	{
		ft_printf("Error\n");
		return (1);
	}
	fill_stack(&a, argc, argv);

	// Imprimir el contenido del stack desde el top hasta el bottom
	for (int j = a.top; j >= 0; j--) { // Cambiado para imprimir desde el top
		ft_printf("%d\n", a.data[j]);
	}

	free(a.data);
	return (0);
}

