/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:53:22 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 12:58:46 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_repeated_int(int count, int *numbers)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
			if (numbers[i] == numbers[j++])
				return (1);
		i++;
	}
	return (0);
}

static int	is_dup_numbers(int argc, char **argv)
{
	int	count;
	int	*numbers;
	int	i;

	count = argc - 1;
	numbers = malloc(count * sizeof(int));
	if (!numbers)
		return (1);
	i = 0;
	while (i < count)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	if (check_repeated_int(count, numbers))
	{
		free(numbers);
		return (1);
	}
	free(numbers);
	return (0);
}

static int	is_valid_integer(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_in_int_range(const char *str)
{
	long	number;

	number = ft_atol(str);
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	return (1);
}

static int	validate_split_input(char *input)
{
	char	**split_list;
	int		j;

	split_list = ft_split(input, ' ');
	if (!split_list)
		return (1);
	j = 0;
	while (split_list[j])
	{
		if (!is_valid_integer(split_list[j]) || !is_in_int_range(split_list[j]))
		{
			free_list(split_list);
			write(2, "Error\n", 6);
			return (1);
		}
		j++;
	}
	free_list(split_list);
	return (0);
}

int	wrong_input(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (validate_split_input(argv[i]))  // Llama a la nueva función
			{
				return (1);
			}
		}
		else
		{
			if (!is_valid_integer(argv[i]) || (!is_in_int_range(argv[i])))
			{
				write(2, "Error\n", 6);
				return (1);
			}
		}
		i++;
	}
	if (is_dup_numbers(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
