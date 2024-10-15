/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:53:22 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/15 18:57:10 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>

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

int	wrong_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_integer(argv[i]) || (!is_in_int_range(argv[i])))
		{
			write(2, "Error\n", 6);
			return (1);
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
