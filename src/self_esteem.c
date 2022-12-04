/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_esteem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:11:29 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 10:45:25 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/*  ----------------------
*    FIND_HIGHEST_INDEX
*	----------------------
*	Retorna o index maior da stack (que corresponde ao maior valor).
*/
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/*  ----------------
*    SELF_ESTEEM
*	----------------
*	Ordena uma stack de 3 números em 2 ou menos movimentos. 
*	É ordenada consoante o index.
*	Exemplo
*		valores:	 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solução, 2 moves:
*	rra:
*		valores:	 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		valores:	 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
void	self_esteem(t_stack **stack)
{
	int		highest;

	if (sort_checker(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
