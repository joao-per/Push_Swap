#include "push_swap.h"

static void	align_stack(t_stack **a, t_stack **b, int *cost_a, int *cost_b, char *stack)
{
	while (*cost_a && ft_strcmp(stack, "rstack"))
	{
		if ((*cost_a)-- > 0)
			do_rotate(a, b, "ra");
		else if ((*cost_a++) < 0)
			do_rrotate(a, b, "rra");
	}
	while (*cost_b && ft_strcmp(stack, "rstack"))
	{
		if ((*cost_b)-- > 0)
			do_rotate(a, b, "rb");
		else if ((*cost_b)++ < 0)
			do_rrotate(a, b, "rrb");
	}
	if (ft_strcmp(stack, "rr"))
	{
		while ((*cost_a)-- > 0 && (*cost_b)-- > 0)
			do_rr(a, b);
	}
	if (ft_strcmp(stack, "rrr"))
	{
		while ((*cost_a)++ < 0 && (*cost_b)++ < 0)
			do_rrr(a, b);
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		align_stack(a, b, &cost_a, &cost_b, "rr");
	else if (cost_a < 0 && cost_b < 0)
		align_stack(a, b, &cost_a, &cost_b, "rrr");
	align_stack(a, b, &cost_a, &cost_b, "rstack");
	do_push(a, b, "pa");
}
