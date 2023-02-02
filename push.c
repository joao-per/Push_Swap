#include "push_swap.h"
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	temp = src;
	if (*src == NULL)
		return ;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	do_push(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "pa") == 0)
	{
		push(stack_b, stack_a);
		ft_putstr("pa\n");
	}
	if (ft_strcmp(op, "pb") == 0)
	{
		push(stack_a, stack_b);
		ft_putstr("pb\n");
	}
}
