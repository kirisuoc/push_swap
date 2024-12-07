/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:26:24 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/07 17:01:22 by ecousill         ###   ########.fr       */
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

static void execute_instructions(char **instructions, int count, t_stack *a, t_stack *b)
{
	int	i;
	i = 0;
	while (i < count)
	{
		if (ft_strcmp(instructions[i], "sa\n") == 0)
			sa_c(a);
		else if (ft_strcmp(instructions[i], "sb\n") == 0)
			sb_c(b);
		else if (ft_strcmp(instructions[i], "ss\n") == 0)
			ss_c(a, b);
		else if (ft_strcmp(instructions[i], "ra\n") == 0)
			ra_c(a);
		else if (ft_strcmp(instructions[i], "rb\n") == 0)
			rb_c(b);
		else if (ft_strcmp(instructions[i], "rr\n") == 0)
			rr_c(a, b);
		else if (ft_strcmp(instructions[i], "rra\n") == 0)
			rra_c(a);
		else if (ft_strcmp(instructions[i], "rrb\n") == 0)
			rrb_c(b);
		else if (ft_strcmp(instructions[i], "rrr\n") == 0)
			rrr_c(a, b);
		else if (ft_strcmp(instructions[i], "pa\n") == 0)
			pa_c(a, b);
		else if (ft_strcmp(instructions[i], "pb\n") == 0)
			pb_c(b, a);
		else
		{
			print_error("Instruction not valid.");
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**instructions;

	int		instructions_count;

	if (ac == 1)
		return (print_error("Error. Enter a list of numbers to be sorted."));
	if (wrong_input(ac, av))
		return (1);
	if (!initialize_stacks(&a, &b, ac, av))
		return (print_error("Error. Unable to initialize stack."));
	instructions = read_instructions(&instructions_count);

	execute_instructions(instructions, instructions_count, &a, &b);
	if (is_sorted(&a))
	{
		ft_printf("OK");
	}
	else
	{
		ft_printf("KO");
	}

	// ¿Chequear si stack b está vacío?


	for (int i = 0; i < instructions_count; i++)
		free(instructions[i]);
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
