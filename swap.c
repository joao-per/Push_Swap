#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	do_swap(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
	{
		swap(*stack_a);
		ft_putstr("sa\n");
	}
	if (ft_strcmp(op, "pb") == 0)
	{
		swap(*stack_b);
		ft_putstr("sb\n");
	}
	if (ft_strcmp(op, "ss") == 0)
	{
		swap(*stack_a);
		swap(*stack_b);
		ft_putstr("ss\n");
	}
}
