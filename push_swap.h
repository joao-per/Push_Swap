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
int			check_ifnb(char *nb);
int			check_dup(char **nb);
int			check_zero(char *nb);
int			check_input(char **nb);

/*				OPERATIONS			*/
void		do_push(t_stack **stack_a, t_stack **stack_b, char *op);
void		do_swap(t_stack **stack_a, t_stack **stack_b, char *op);
void		do_rotate(t_stack **stack_a, t_stack **stack_b, char *op);
void		do_rrotate(t_stack **stack_a, t_stack **stack_b, char *op);
void		align_stack(t_stack **a, t_stack **b, int *cost_a, int *cost_b);

/*				SORTS				*/
int			sort_checker(t_stack *stack);
void		sort_three(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);

/*				UTILS				*/
int			is_digit(char c);
int			ft_atol(const char *str);
int			abs_vl(int nb);
void		freexit(t_stack **stack_a, t_stack **stack_b);

/*				STACKS				*/
t_stack		*fill_stack_nbs(int ac, char **av);

/*				COST				*/
int		get_stack_size(t_stack	*stack);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	stack_add_bottom(t_stack **stack, t_stack *new);
t_stack	*new_stack(int nb);
t_stack	*get_bottom_nb(t_stack *stack);
t_stack	*get_penultimo_nb(t_stack *stack);

/*			POS_AND_INDEX			*/
int			get_minor_pos(t_stack **stack);
void		get_target_pos(t_stack **a, t_stack **b);
void		set_index(t_stack *stack_a, int stack_size);
void		get_cost(t_stack **stack_a, t_stack **stack_b);


#endif