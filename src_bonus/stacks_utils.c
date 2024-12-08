/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:21:00 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/07 22:21:29 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

int	initialize_stacks(t_stack *a, t_stack *b, int argc, char **argv)
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

void	fill_stack(t_stack *a, int counter, char **matrix)
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

int	check_stack_allocation(t_stack *a, t_stack *b, char **list)
{
	if (!a->data || !b->data)
	{
		free_list(list);
		return (0);
	}
	return (1);
}
