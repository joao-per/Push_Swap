/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:13:53 by joao-per          #+#    #+#             */
/*   Updated: 2022/12/04 23:13:54 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  -----------------
*	SORT_CHECKER
*	-----------------
*	DESCRIÇÃO
*	Verifica se a stack está sorteada corretamente.
*	(Os valores dados podem estar corretos logo de partida)
*	VARIÁVEIS
*	#1. A Stack
*/
int	sort_checker(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
