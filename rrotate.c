#include "push_swap.h"

static void rrotate(t_stack **stack)
{
	t_stack *head = *stack;
	t_stack *before_tail = get_penultimo_value(*stack);
	t_stack *tail = get_bottom_value(*stack);

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	before_tail->next = NULL;
	tail->next = head;
	*stack = tail;
}

void	do_rrotate(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "rra") == 0)
	{
		rrotate(stack_a);	
		ft_putstr("rra\n");
	}
	else if (ft_strcmp(op, "rrb") == 0)
	{
		rrotate(stack_b);
		ft_putstr("rrb\n");
	}
	else if (ft_strcmp(op, "rrr") == 0)
	{
		rrotate(stack_a);
		rrotate(stack_b);
		ft_putstr("rrr\n");
	}
}
