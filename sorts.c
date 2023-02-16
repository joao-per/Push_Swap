#include "push_swap.h"

void	sort_three(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->number;
	b = (*stack_a)->next->number;
	c = (*stack_a)->next->next->number;
	if (a < b && b > c && c > a)
	{
		do_swap(stack_a, stack_b, "sa");
		do_rotate(stack_a, stack_b, "ra");
	}
	else if (a > b && c > a && c > b)
		do_swap(stack_a, stack_b, "sa");
	else if (a < b && b > c && c < a)
		do_rrotate(stack_a, stack_b, "rra");
	else if (a > b && b < c)
		do_rotate(stack_a, stack_b, "ra");
	else if (a > b && b > c)
	{
		do_swap(stack_a, stack_b, "sa");
		do_rrotate(stack_a, stack_b, "rra");
	}
}

static void	sorts(t_stack **stack_a, t_stack **stack_b, int size)
{
	if(!sort_checker(*stack_a))
	{
		if (size == 2)
			do_sa(stack_a);
		else if (size == 3)
			sort_three(stack_a, stack_b);
		else
			sort(stack_a, stack_b);
	}
}