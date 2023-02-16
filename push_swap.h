#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				index;
	int				number;
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
/*				SORTS				*/
int			find_highest(t_stack *stack);

/*				UTILS				*/
int			is_digit(char c);
int			ft_atol(const char *str);


#endif