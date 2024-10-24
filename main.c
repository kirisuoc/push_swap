/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:06:44 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 12:10:07 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void free_list(char **list)
{
	int i;

	i = 0;
	while (list[i])
	{
		free(list[i]);  // Liberar cada cadena individualmente
		i++;
	}
	free(list);  // Liberar el array de punteros
}

static void	fill_stack(t_stack *a, int counter, char **matrix)
{
	int i;

	i = 0;
	a->top = counter - 1;
	while (i < counter)
	{
		a->data[i] = ft_atoi(matrix[counter - i - 1]);
		i++;
	}
}


static void	sort_list(t_stack *a, t_stack *b)
{
 	if (a->top + 1 == 3)
	{
		short_list(a);
	}
	else if (a->top + 1 <= 5)
	{
		medium_list(a, b);
	}
	else
		sort_big_stack(a, b);
}



int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	char	**list;
	int		size;

	if (argc == 1)
		return (1);
/* 	if (wrong_input(argc, argv))
		return (1); */


	if (argc > 2)
	{

		a.data = ft_calloc((argc - 1), sizeof(int));
		b.data = ft_calloc((argc - 1), sizeof(int));
			if (!a.data || !b.data)
		return (1);
		fill_stack(&a, argc - 1, argv + 1);
	}
	else if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		size = 0;
		while (list[size])
			size++;
		a.data = ft_calloc(size, sizeof(int));
		b.data = ft_calloc(size, sizeof(int));
		if (!a.data || !b.data)
		{
			free_list(list);
			return (1);
		}
		fill_stack(&a, size, list);
		free_list(list);
	}

	if (is_sorted(&a))
	{
		free(a.data);
		free(b.data);
		return (0);
	}
	b.top = -1;

	sort_list(&a, &b);

 	 							// Imprimir el contenido del stack A desde el top hasta el bottom
/* 							ft_printf("\n");

 							for (int j = a.top; j >= 0; j--) {
								ft_printf("%d ", a.data[j]);
								ft_printf("%d", b.data[j]);
								ft_printf("\n");
							}
							ft_printf("_ _\na b\n");

							ft_printf("%d\n", b.top); */

	free(a.data);
	free(b.data);
	return (0);
}
