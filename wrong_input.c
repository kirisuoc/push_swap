/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:53:22 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 13:10:47 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (validate_split_input(argv[i]))
				return (1);
		}
		else if (!is_valid_integer(argv[i]) || (!is_in_int_range(argv[i])))
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
