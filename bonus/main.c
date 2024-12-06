/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:26:24 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/06 21:12:09 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../includes/push_swap.h"

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

void	read_instructions()
{

}

int	main(int ac, char **av)
{
	t_stack a;
	t_stack b;

	if (av == 1);
		return (1);
	if (wrong_input(ac, av))
		return (1);
	if (!initialize_stacks(&a, &b, ac, av))
	return (0);
}
