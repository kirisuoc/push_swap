/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:02:19 by ecousill          #+#    #+#             */
/*   Updated: 2024/10/24 16:05:14 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_repeated_int(int count, int *numbers)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_dup_numbers(int count, char **argv)
{
	int	*numbers;
	int	i;
	int	result;

	numbers = malloc(count * sizeof(int));
	if (!numbers)
	{
		return (1);
	}
	i = 0;
	while (i < count)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	result = check_repeated_int(count, numbers);
	free(numbers);
	return (result);
}

int	is_valid_integer(const char *str)
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

int	is_in_int_range(const char *str)
{
	long number;

	number = ft_atol(str);
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	return (1);
}
