/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:11:26 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/28 18:04:28 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/*  ----------
*    SWAP
*	----------
*	Troca os dois primeiros elementos de uma stack.
*	Não faz nada caso só exista 1 ou nenhum elemento.
*/
static void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

/*  ----------
*    Swap A
*	----------
*	Faz Swap na stack A e imprime "sa".
*/
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/*  ----------
*    Swap B
*	----------
*	Faz Swap na stack B e imprime "sb".
*/
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/*  -------------
*    Swap A & B
*	-------------
*	Faz Swap na stack A & B e imprime "ss".
*/
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
