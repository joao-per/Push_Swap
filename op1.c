/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:25:04 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/01 17:25:04 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = *src;
	if (*src == NULL)
		return ;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	do_push(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "pa") == 0)
	{
		push(stack_b, stack_a);
		ft_putstr("pa\n");
	}
	if (ft_strcmp(op, "pb") == 0)
	{
		push(stack_a, stack_b);
		ft_putstr("pb\n");
	}
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_swap(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
	{
		swap(*stack_a);
		ft_putstr("sa\n");
	}
	if (ft_strcmp(op, "sb") == 0)
	{
		swap(*stack_b);
		ft_putstr("sb\n");
	}
	if (ft_strcmp(op, "ss") == 0)
	{
		swap(*stack_a);
		swap(*stack_b);
		ft_putstr("ss\n");
	}
}
