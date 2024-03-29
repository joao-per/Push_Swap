/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:25:22 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/01 17:25:22 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rush_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;
	int	i;

	size_a = lstsize(*stack_a);
	size_b = 0;
	i = -1;
	while (size_a > 6 && ++i < size_a && size_b < size_a / 2)
	{
		if ((*stack_a)->index <= size_a / 2)
		{
			do_push(stack_a, stack_b, "pb");
			size_b++;
		}
		else
			do_rotate(stack_a, stack_b, "ra");
	}
	while (size_a - size_b++ > 3)
		do_push(stack_a, stack_b, "pb");
	if (check_order(stack_a) == 0)
		sort_three(stack_a, stack_b);
}

void	fix_order(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest_pos;
	int	size;

	size = lstsize(*stack_a);
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

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	rush_b(stack_a, stack_b);
	while (*stack_b)
	{
		set_best_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
}
