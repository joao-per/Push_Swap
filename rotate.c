#include "push_swap.h"

static void rotate(t_stack **stack)
{
    t_stack *head = *stack;
    t_stack *second = (*stack)->next;
    t_stack *tail = get_bottom_value(*stack);

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    head->next = NULL;
    tail->next = head;
    *stack = second;
}

void	do_rotate(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
	{
		rotate(stack_a);	
		ft_putstr("ra\n");
	}
	else if (ft_strcmp(op, "rb") == 0)
	{
		rotate(stack_b);
		ft_putstr("rb\n");
	}
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_putstr("rr\n");
	}
}
