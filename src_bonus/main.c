/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:26:24 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/08 13:14:27 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static char	**read_instructions(int *instructions_count);

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
	b.top = -1;
	execute_instructions(instructions, instructions_count, &a, &b);
	if (is_sorted(&a) && b.top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_instructions(instructions, instructions_count);
	free_stacks(a, b);
	return (0);
}

// Intentar implementar sin realloc
static char	**read_instructions(int *count)
{
	char	**instructions;
	char	*line;

	instructions = NULL;
	line = NULL;
	*count = 0;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		instructions = realloc(instructions, (*count + 1) * sizeof(char *));
		if (instructions == NULL)
		{
			perror("Error allocating memory.");
			exit(1);
		}
		instructions[*count] = line;
		(*count)++;
		line = get_next_line(0);
	}
	return (instructions);
}
