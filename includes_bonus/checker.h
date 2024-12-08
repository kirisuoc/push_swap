/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:25:06 by erikcousill       #+#    #+#             */
/*   Updated: 2024/12/08 13:14:19 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/libftprintf.h"
# include "../gnl/get_next_line.h"

typedef struct s_stack
{
	int	*data;
	int	top;
}		t_stack;

void	sa_c(t_stack *a);
void	sb_c(t_stack *b);
void	ss_c(t_stack *a, t_stack *b);
void	pa_c(t_stack *a, t_stack *b);
void	pb_c(t_stack *b, t_stack *a);
void	ra_c(t_stack *a);
void	rb_c(t_stack *b);
void	rr_c(t_stack *a, t_stack *b);
void	rra_c(t_stack *a);
void	rrb_c(t_stack *b);
void	rrr_c(t_stack *a, t_stack *b);

// main.c
int		print_error(char *error_message);

// exec_instructions.c
void	execute_instructions(char **instr, int count, \
			t_stack *a, t_stack *b);

// stacks_utils.c
int		initialize_stacks(t_stack *a, t_stack *b, int argc, char **argv);
void	fill_stack(t_stack *a, int counter, char **matrix);
int		check_stack_allocation(t_stack *a, t_stack *b, char **list);

// wrong_input.c
int		wrong_input(int argc, char **argv);

// wrong_input_utils.c
int		is_valid_integer(const char *str);
int		is_in_int_range(const char *str);
int		is_dup_numbers(int count, char **argv);
int		check_repeated_int(int count, int *numbers);

// general_utils.c
int		is_sorted(t_stack *a);

// free.c
void	free_resources(int *numbers, char **split_lst);
void	free_list(char **list);
void	free_stacks(t_stack a, t_stack  b);
void	free_instructions(char **instructions, int instr_count);

// errors.c
int		print_error(char *error_message);

#endif
