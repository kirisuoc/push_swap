/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:53:22 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 16:53:01 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_resources(int *numbers, char **split_lst)
{
	free(numbers);
	free_list(split_lst);
}

static int	convert_and_validate_numbers(char **split_lst, int count,
		int *numbers)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_valid_integer(split_lst[i]) || !is_in_int_range(split_lst[i]))
			return (1);
		numbers[i] = ft_atoi(split_lst[i]);
		i++;
	}
	return (0);
}

static int	validate_split_input(char *input)
{
	char	**split_lst;
	int		j;
	int		*numbers;

	split_lst = ft_split(input, ' ');
	if (!split_lst)
		return (1);
	j = 0;
	while (split_lst[j])
		j++;
	numbers = malloc(j * sizeof(int));
	if (!numbers)
	{
		free_list(split_lst);
		return (1);
	}
	if (convert_and_validate_numbers(split_lst, j, numbers)
		|| check_repeated_int(j, numbers))
	{
		free_resources(numbers, split_lst);
		write(2, "Error\n", 6);
		return (1);
	}
	free_resources(numbers, split_lst);
	return (0);
}

int	wrong_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (validate_split_input(argv[i]))
			{
				return (1);
			}
		}
		else if (!is_valid_integer(argv[i]) || !is_in_int_range(argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	if (is_dup_numbers(argc - 1, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
