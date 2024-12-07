/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:26:24 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/07 22:27:57 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static char	**read_instructions(int *instructions_count);
static void	execute_instructions(char **instructions, int count, \
			t_stack *a, t_stack *b);

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**instructions;
	int		instructions_count;
	int		i;

	if (ac == 1)
		return (print_error("Error. Enter a list of numbers to be sorted."));
	if (wrong_input(ac, av))
		return (1);
	if (!initialize_stacks(&a, &b, ac, av))
		return (print_error("Error. Unable to initialize stack."));
	instructions = read_instructions(&instructions_count);
	b.top = -1;
	execute_instructions(instructions, instructions_count, &a, &b);
	if (is_sorted(&a) && b.top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	i = 0;
	while (i < instructions_count)
		free(instructions[i++]);
	free (instructions);
	return (0);
}

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
		if (ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		instructions = realloc(instructions, (count + 1) * sizeof(char *));
		if (instructions == NULL)
		{
			ft_printf("Error al asignar memoria.");
			exit(1);
		}
		instructions[count] = line;
		count++;
	}
	*instructions_count = count;
	return (instructions);
}

static void	execute_instructions(char **instructions, int count, \
			t_stack *a, t_stack *b)
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
