/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_and_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:24:17 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/01 17:24:17 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i++;
		tmp = tmp->next;
	}
}

int	get_minor_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_position;

	tmp = *stack;
	lowest_index = INT_MAX;
	set_position(stack);
	lowest_position = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_position);
}

static int	best_pos(t_stack **a, int b_idx,
								int target_idx, int position)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			position = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (position);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			position = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (position);
}

void	set_best_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		position;

	tmp_b = *b;
	set_position(a);
	set_position(b);
	position = 0;
	while (tmp_b)
	{
		position = best_pos(a, tmp_b->index, INT_MAX, position);
		tmp_b->target_position = position;
		tmp_b = tmp_b->next;
	}
}

void	set_index(t_stack *stack_a, int stack_size)
{
	t_stack	*tmp;
	t_stack	*highest;
	int		number;

	while (--stack_size > 0)
	{
		tmp = stack_a;
		number = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->number == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->number > number && tmp->index == 0)
			{
				number = tmp->number;
				highest = tmp;
				tmp = stack_a;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
