/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:00:11 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/08 13:04:09 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static void	execute_swap(char *instr, t_stack *a, t_stack *b);
static void	execute_reverse(char *instr, t_stack *a, t_stack *b);
static void	execute_rev_rotate(char *instr, t_stack *a, t_stack *b);
static void	execute_push(char *instr, t_stack *a, t_stack *b);

void	execute_instructions(char **inst, int count, \
			t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!ft_strcmp(inst[i], "sa\n") || !ft_strcmp(inst[i], "sb\n") \
			|| !ft_strcmp(inst[i], "ss\n"))
			execute_swap(inst[i], a, b);
		else if (!ft_strcmp(inst[i], "ra\n") || !ft_strcmp(inst[i], "rb\n") \
			|| !ft_strcmp(inst[i], "rr\n"))
			execute_reverse(inst[i], a, b);
		else if (!ft_strcmp(inst[i], "rra\n") || !ft_strcmp(inst[i], "rrb\n") \
			|| !ft_strcmp(inst[i], "rrr\n"))
			execute_rev_rotate(inst[i], a, b);
		else if (!ft_strcmp(inst[i], "pa\n") || !ft_strcmp(inst[i], "pb\n"))
			execute_push(inst[i], a, b);
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
