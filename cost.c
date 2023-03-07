/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:24:07 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/01 17:24:07 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = lstsize(tmp_a);
	size_b = lstsize(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_position;
		if (tmp_b->target_position > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_position) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (neg_to_pos(tmp->cost_a) + neg_to_pos(tmp->cost_b)
			< neg_to_pos(cheapest))
		{
			cheapest = neg_to_pos(tmp->cost_b) + neg_to_pos(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	align_stack(stack_a, stack_b, cost_a, cost_b);
}

void	align_stack(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		while (cost_a > 0 && cost_b > 0 && cost_a-- && cost_b--)
			do_rotate(a, b, "rr");
		while (cost_a < 0 && cost_b < 0 && cost_a++ && cost_b++)
			do_rrotate(a, b, "rrr");
	}
	while (cost_a)
	{
		if (cost_a > 0 && cost_a--)
			do_rotate(a, b, "ra");
		else if (cost_a < 0 && cost_a++)
			do_rrotate(a, b, "rra");
	}
	while (cost_b)
	{
		if (cost_b > 0 && cost_b--)
			do_rotate(a, b, "rb");
		else if (cost_b < 0 && cost_b++)
			do_rrotate(a, b, "rrb");
	}
	do_push(a, b, "pa");
}
