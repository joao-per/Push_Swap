/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:50:34 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/07 10:43:38 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "checker.h"

void	pushz(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	temp = *src;
	if (*src == NULL)
		return ;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	do_pushz(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "pa") == 0)
	{
		pushz(stack_b, stack_a);
	}
	if (ft_strcmp(op, "pb") == 0)
	{
		pushz(stack_a, stack_b);
	}
}

void	swapz(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	do_swapz(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
	{
		swapz(*stack_a);
	}
	if (ft_strcmp(op, "sb") == 0)
	{
		swapz(*stack_b);
	}
	if (ft_strcmp(op, "ss") == 0)
	{
		swapz(*stack_a);
		swapz(*stack_b);
	}
}
