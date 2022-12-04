/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:13:47 by joao-per          #+#    #+#             */
/*   Updated: 2022/12/03 02:38:58 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define FAIL 0
# define SUCCESS 1

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Start Stack */

t_stack		*fill_stack_values(int ac, char **av);
void		set_index(t_stack *stack_a, int ac);

/* Algorítmos */

int			sort_checker(t_stack *stack);
void		self_esteem(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Posição */

int			get_minor_index_pos(t_stack **stack);
void		get_target_pos(t_stack **stack_a, t_stack **stack_b);

/* Custo */

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Calcular moves */

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operações Possíveis */

void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);

/* Funções das stacks */

t_stack		*get_bottom_value(t_stack *stack);
t_stack		*get_penultimo_value(t_stack *stack);
t_stack		*new_stack(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

/* Funções auxiliares */

void		free_stack(t_stack **stack);
void		exit_error(t_stack **stack_a, t_stack **stack_b);

/* Input Checker */
int			input_checker(char **av);

#endif