/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:36:57 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/08 13:14:08 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

void	free_resources(int *numbers, char **split_lst)
{
	free(numbers);
	free_list(split_lst);
}

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	free_stacks(t_stack a, t_stack  b)
{
	free(a.data);
	free(b.data);
}

void	free_instructions(char **instructions, int instr_count)
{
	int	i;

	i = 0;
		while (i < instr_count)
		free(instructions[i++]);
	free (instructions);
}
