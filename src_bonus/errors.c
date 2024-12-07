/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:50:51 by ecousill          #+#    #+#             */
/*   Updated: 2024/12/07 15:51:06 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

int	print_error(char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n", 1);
	return (1);
}
