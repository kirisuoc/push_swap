/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:06:44 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/18 18:57:55 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->top < 1)
		return (1);
	i = 0;
	while (i < a->top)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}


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
		big_stack(a, b);
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
		return (0);
	}
	b.top = -1;

	sort_list(&a, &b);

/*    							// Imprimir el contenido del stack A desde el top hasta el bottom
							ft_printf("\n");

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

// ARG="40 20 55 9 53 5 7 90 4 1 50 23 28 79 3 13 101 36 63 98 17"; ./push_swap $ARG | ./checker_Mac $ARG

// ARG="40 20 55 9 53 5 7 90 4 1 50 23 28 79 3 13 101 36 63 98 17"; ./push_swap $ARG | wc -l

// 78 45 23 67 12 89 56 34 90 11 3 82 39 5 27 70 41 99 20 62 36 88 15 74 54 4 33 13 73 29 22 98 1 95 57 10 60 83 77 2 94 46 17 68 75 25 42 80 81 69 63 19 44 40 76 9 26 16 50 31 8 7 24 65 30 14 47 32 97 48 59 91 61 86 52 72 55 35 18 92 37 84 38 49 64 85 87 66 93 58 71 100 53
