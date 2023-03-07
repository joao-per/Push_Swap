/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:34:44 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/07 10:44:01 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotatez(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*last;

	head = *stack;
	second = head->next;
	last = last_node(*stack);
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head->next = NULL;
	last->next = head;
	*stack = second;
}

void	do_rotatez(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
	{
		rotatez(stack_a);
	}
	else if (ft_strcmp(op, "rb") == 0)
	{
		rotatez(stack_b);
	}
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotatez(stack_a);
		rotatez(stack_b);
	}
}

static void	rrotatez(t_stack **stack)
{
	t_stack	*head;
	t_stack	*before_last;
	t_stack	*last;

	head = *stack;
	before_last = before_last_node(*stack);
	last = last_node(*stack);
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	before_last->next = NULL;
	last->next = head;
	*stack = last;
}

void	do_rrotatez(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "rra") == 0)
	{
		rrotatez(stack_a);
	}
	else if (ft_strcmp(op, "rrb") == 0)
	{
		rrotatez(stack_b);
	}
	else if (ft_strcmp(op, "rrr") == 0)
	{
		rrotatez(stack_a);
		rrotatez(stack_b);
	}
}
