/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:25:29 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/01 17:25:29 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	neg_to_pos(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free (*lst);
		*lst = temp;
	}
	lst = NULL;
}

void	freexit(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		lstclear(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		lstclear(stack_b);
	ft_putstr("Error\n");
	exit (1);
}
