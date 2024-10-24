/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:49:23 by erikcousill       #+#    #+#             */
/*   Updated: 2024/10/24 11:14:02 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./libft/libftprintf.h"

// Definiciones de códigos de color ANSI
#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"
#define GRAY       "\033[90m"


typedef struct s_stack
{
	int	*data;
	int	top;
}		t_stack;

typedef struct s_move
{
	int	index;
	int	max_number;
	int	min_number;
	int	distance_ra;	// Creo que no hace falta
	int	distance_rra;
	int	is_reverse_a;
	int	is_reverse_b;
	int	is_reverse_b_temp;


}		t_moves;


void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b);

int		wrong_input(int argc, char **argv);

int		is_sorted(t_stack *a);
int		is_sorted_reverse(t_stack *a);
int		get_smallest_number(t_stack *a);
int		get_largest_number(t_stack *b);

void	short_list(t_stack *a);
void	medium_list(t_stack *a, t_stack *b);
void	merge_sort_stack(t_stack *a, t_stack *b, int size);

void	sort_big_stack(t_stack *a, t_stack *b);

void	get_cheaper_index(t_stack *a, t_stack *b, t_moves *next_move);


#endif
