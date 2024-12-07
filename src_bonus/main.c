/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:26:24 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/07 14:31:01 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static void	fill_stack(t_stack *a, int counter, char **matrix);
static int	initialize_stacks(t_stack *a, t_stack *b, int argc, char **argv);
static int	check_stack_allocation(t_stack *a, t_stack *b, char **list);
static char	**read_instructions(int *instructions_count);

// Intentar implementar sin realloc
static char	**read_instructions(int *instructions_count)
{
	char	**instructions;
	char	*line;
	int		count;

	instructions = NULL;
	line = NULL;
	count = 0;
	while ((line = get_next_line(0)) != NULL)
	{
		// Si la línea está vacía, terminamos
		if (ft_strlen(line) == 0)
		{
			free(line);
			break;
		}
		// Reserva espacio para la nueva instrucción
		instructions = realloc(instructions, (count + 1) * sizeof(char *));
		if (instructions == NULL)
		{
			ft_printf("Error al asignar memoria.");
			exit(1);
		}

		// Asigna memoria para la cadena y copia la instrucción
		instructions[count] = line;
		count++;
	}
	*instructions_count = count;
	return (instructions);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**instructions;

	int		instructions_count;

	if (ac == 1)
	{
		ft_printf("1");
		return (1);
	}
	if (wrong_input(ac, av))
	{
		ft_printf("2");
		return (1);
	}
	if (!initialize_stacks(&a, &b, ac, av))
	{
		ft_printf("3");
	}

	instructions = read_instructions(&instructions_count);
	for (int i = 0; i < instructions_count; i++)
	{
		ft_printf("%s", instructions[i]);
		free(instructions[i]);
	}
	free (instructions);
	return (0);
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

static int	check_stack_allocation(t_stack *a, t_stack *b, char **list)
{
	if (!a->data || !b->data)
	{
		free_list(list);
		return (0);
	}
	return (1);
}
