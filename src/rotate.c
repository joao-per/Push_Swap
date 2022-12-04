/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:11:16 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/28 18:04:22 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/* -----------------
*   ROTATE
*  -----------------
*	Envia o primeiro elemento da stack para o fundo.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack;
	*stack = (*stack)->next;
	tail = get_bottom_value(*stack);
	temp->next = NULL;
	tail->next = temp;
}

/* -----------------
*   ROTATE A
*  -----------------
*	Faz Rotate na stack A e imprime "ra"
*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/* -----------------
*   ROTATE B
*  -----------------
*	Faz Rotate na stack B e imprime "rb"
*/
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/* -----------------
*   ROTATE A & B
*  -----------------
*	Faz Rotate na stack A & B e imprime "rr"
*/
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
