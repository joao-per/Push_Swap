/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:24:01 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/01 17:24:01 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
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

static void	rrotate(t_stack **stack)
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
