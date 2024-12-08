/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:06:44 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 23:07:06 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_stack(t_stack *a, int counter, char **matrix)
{
	int	i;

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

static int	check_stack_allocation(t_stack *a, t_stack *b, char **list)
{
	if (!a->data || !b->data)
	{
		free_list(list);
		return (0);
	}
	return (1);
}

static int	initialize_stacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	char	**list;
	int		size;

	if (argc > 2)
	{
		a->data = ft_calloc((argc - 1), sizeof(int));
		b->data = ft_calloc((argc - 1), sizeof(int));
		if (!a->data || !b->data)
			return (0);
		fill_stack(a, argc - 1, argv + 1);
	}
	else if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		size = 0;
		while (list[size])
			size++;
		a->data = ft_calloc(size, sizeof(int));
		b->data = ft_calloc(size, sizeof(int));
		if (!check_stack_allocation(a, b, list))
			return (0);
		fill_stack(a, size, list);
		free_list(list);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (1);
	if (wrong_input(argc, argv))
		return (1);
	if (!initialize_stacks(&a, &b, argc, argv))
		return (1);
	if (is_sorted(&a))
	{
		free(a.data);
		free(b.data);
		return (0);
	}
	b.top = -1;
	sort_list(&a, &b);
	free(a.data);
	free(b.data);
	return (0);
}
