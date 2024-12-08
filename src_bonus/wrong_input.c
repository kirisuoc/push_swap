/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:32:21 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/07 22:15:02 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static int	validate_split_input(char *input);
static int	convert_and_validate_numbers(char **split_lst, int count,
				int *numbers);

int	wrong_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (validate_split_input(argv[i]))
				return (1);
		}
		else if (!is_valid_integer(argv[i]) || !is_in_int_range(argv[i]))
			return (print_error("Error. Invalid integer."));
		i++;
	}
	if (is_dup_numbers(argc - 1, argv))
		return (print_error("Error. Duplicated numbers found."));
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
		return (print_error(\
			"Error. Invalid integer or repeated numbers found."));
	}
	free_resources(numbers, split_lst);
	return (0);
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
