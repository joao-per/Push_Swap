#include "push_swap.h"

static void	get_pos(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

int	get_minor_pos(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		lowest_position;

	temp = *stack;
	lowest_index = INT_MAX;
	get_pos(stack);
	lowest_position = temp->position;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_position = temp->position;
		}
		temp = temp->next;
	}
	return (lowest_position);
}

static int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index > b_idx && temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

void	get_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		position;

	temp_b = *b;
	get_pos(a);
	get_pos(b);
	position = 0;
	while (temp_b)
	{
		position = get_target(a, temp_b->index, INT_MAX, position);
		temp_b->target_position = position;
		temp_b = temp_b->next;
	}
}


void	set_index(t_stack *stack_a, int stack_size)
{
	t_stack	*temp;
	t_stack	*highest;
	int		number;

	while (--stack_size > 0)
	{
		temp = stack_a;
		number = INT_MIN;
		highest = NULL;
		while (temp)
		{
			if (temp->number == INT_MIN && temp->index == 0)
				temp->index = 1;
			if (temp->number > number && temp->index == 0)
			{
				number = temp->number;
				highest = temp;
				temp = stack_a;
			}
			else
				temp = temp->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
