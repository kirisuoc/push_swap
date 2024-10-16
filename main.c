/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:06:44 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/16 17:45:53 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libft/libftprintf.h"
#include "push_swap.h"

static int	is_sorted(t_stack *a)
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

void	list_upto_5(t_stack *a, t_stack *b)
{
	while (a->top > 2)
		pb(b, a);
	short_list(a);
	while (b->top > -1)
	{
		if (b->data[b->top] < a->data[a->top])
			pa(a, b);
		else if (b->data[b->top] > a->data[0])
		{
			pa(a, b);
			ra(a, 1);
		}
		else
		{
			while (b->data[b->top] > a->data[a->top] || b->data[b->top] < a->data[0])
				ra(a, 1);
			pa(a, b);

		}
		while (!is_sorted(a))
			rra(a, 1);
	}
}


void	sort_list(t_stack *a, t_stack *b)
{
	if (a->top + 1 == 3)
	{
		short_list(a);
	}
	else if (a->top + 1 <= 5)
	{
		list_upto_5(a, b);
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

  							// Imprimir el contenido del stack A desde el top hasta el bottom
							ft_printf("\n");

 							for (int j = a.top; j >= 0; j--) {
								ft_printf("%d ", a.data[j]);
								ft_printf("%d", b.data[j]);
								ft_printf("\n");
							}
							ft_printf("_ _\na b\n");

							ft_printf("%d\n", b.top);
	free(a.data);
	free(b.data);
	return (0);
}

