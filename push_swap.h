/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:49:57 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/06 10:49:57 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				index;
	int				number;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
}	t_stack;

/*				CHECKER				*/
int			check_ifnb(int ac, char **nb);
int			check_dup(char **nb);
int			check_zero(char *nb);
int			check_input(int ac, char **nb);

/*				OPERATIONS			*/
void		do_push(t_stack **stack_a, t_stack **stack_b, char *op);
void		do_swap(t_stack **stack_a, t_stack **stack_b, char *op);
void		do_rotate(t_stack **stack_a, t_stack **stack_b, char *op);
void		do_rrotate(t_stack **stack_a, t_stack **stack_b, char *op);
void		align_stack(t_stack **a, t_stack **b, int cost_a, int cost_b);

/*				SORTS				*/
void		sort_three(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);
void		rush_b(t_stack **stack_a, t_stack **stack_b);
void		fix_order(t_stack **stack_a, t_stack **stack_b);

/*				UTILS				*/
int			neg_to_pos(int nb);
void		lstclear(t_stack **lst);
void		freexit(t_stack **stack_a, t_stack **stack_b);

/*				STACKS				*/
t_stack		*create_list(int ac, char **av);
t_stack		*last_node(t_stack *lst);
int			check_order(t_stack **stack);
int			lstsize(t_stack	*stack);
void		add_back(t_stack **lst, t_stack *new);

/*				COST				*/
t_stack		*new_stack(int nb);
t_stack		*before_last_node(t_stack *lst);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void		get_cost(t_stack **stack_a, t_stack **stack_b);

/*			POS_AND_INDEX			*/
void		set_index(t_stack *stack_a, int stack_size);
void		set_best_pos(t_stack **a, t_stack **b);
int			get_minor_pos(t_stack **stack);

#endif