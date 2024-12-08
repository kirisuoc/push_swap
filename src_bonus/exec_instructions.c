/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:00:11 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/08 12:10:32 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static void	execute_swap(char *instr, t_stack *a, t_stack *b);
static void	execute_reverse(char *instr, t_stack *a, t_stack *b);
static void	execute_rev_rotate(char *instr, t_stack *a, t_stack *b);
static void	execute_push(char *instr, t_stack *a, t_stack *b);

void	execute_instructions(char **instr, int count, \
			t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ft_strcmp(instr[i], "sa\n") || ft_strcmp(instr[i], "sb\n") \
			|| ft_strcmp(instr[i], "ss\n") == 0)
			execute_swap(instr[i], a, b);
		else if (ft_strcmp(instr[i], "ra\n") || ft_strcmp(instr[i], "rb\n") \
			|| ft_strcmp(instr[i], "rr\n") == 0)
			execute_reverse(instr[i], a, b);
		else if (ft_strcmp(instr[i], "rra\n") || ft_strcmp(instr[i], "rrb\n") \
			|| ft_strcmp(instr[i], "rrr\n") == 0)
			execute_rev_rotate(instr[i], a, b);
		else if (ft_strcmp(instr[i], "pa\n") || ft_strcmp(instr[i], "pb\n"))
			execute_push(instr[i], a, b);
		else
		{
			print_error("Instruction not valid.");
			exit(1);
		}
		i++;
	}
}

static void	execute_swap(char *instr, t_stack *a, t_stack *b)
{
	if (ft_strcmp(instr, "sa\n") == 0)
		sa_c(a);
	else if (ft_strcmp(instr, "sb\n") == 0)
		sb_c(b);
	else if (ft_strcmp(instr, "ss\n") == 0)
		ss_c(a, b);
}

static void	execute_reverse(char *instr, t_stack *a, t_stack *b)
{
	if (ft_strcmp(instr, "ra\n") == 0)
		ra_c(a);
	else if (ft_strcmp(instr, "rb\n") == 0)
		rb_c(b);
	else if (ft_strcmp(instr, "rr\n") == 0)
		rr_c(a, b);
}

static void	execute_rev_rotate(char *instr, t_stack *a, t_stack *b)
{
	if (ft_strcmp(instr, "rra\n") == 0)
		rra_c(a);
	else if (ft_strcmp(instr, "rrb\n") == 0)
		rrb_c(b);
	else if (ft_strcmp(instr, "rrr\n") == 0)
		rrr_c(a, b);
}

static void	execute_push(char *instr, t_stack *a, t_stack *b)
{
	if (ft_strcmp(instr, "pa\n") == 0)
		pa_c(a, b);
	else if (ft_strcmp(instr, "pb\n") == 0)
		pb_c(b, a);
}
