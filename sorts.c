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

static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;
	int	i;

	size_a = get_stack_size(*stack_a);
	size_b = 0;
	i = -1;
	while (size_a > 6 && ++i < size_a && size_b < size_a / 2)
	{
		if ((*stack_a)->index <= size_a/ 2)
		{
			do_push(stack_a, stack_b, "pb");
			size_b++;
		}
		else
			do_rotate(stack_a, stack_b, "rb");
	}
	while (size_a - size_b > 3)
	{
		do_pb(stack_a, stack_b);
		size_b++;
	}
}

/*  ---------------
*    SHIFT_STACK
*	---------------
*	Depois que a maior parte da stack é ordenada,
*	desloca a stack A até que o valor menor esteja no topo.
*	Se estiver na metade inferior da stack, dá reverese rotate, 
*	caso contrário, dá rotate até que esteja no topo da stack.
*/
static void	shift_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest_pos;
	int	size;

	size = get_stack_size(*stack_a);
	lowest_pos = get_minor_pos(stack_a);
	if (lowest_pos < size / 2)
	{
		while (lowest_pos-- > 0)
			do_rotate(stack_a, stack_b, "ra");
	}
	else
	{
		while (lowest_pos++ < size)
			do_rrotate(stack_a, stack_b, "rra");
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (abs_vl(temp->cost_a) + abs_vl(temp->cost_b) < abs_vl(cheapest))
		{
			cheapest = abs_vl(temp->cost_b) + abs_vl(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!sort_checker(*stack_a))
		shift_stack(stack_a, stack_b);
}
