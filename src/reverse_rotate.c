/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:11:13 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/28 18:04:20 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/* -----------------
*   REVERSE ROTATE
*  -----------------
*	Eleva o último elemento da stack para o topo.
*/
static void	rrotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_bottom_value(*stack);
	before_tail = get_penultimo_value(*stack);
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
	before_tail->next = NULL;
}

/* -----------------
*   REVERSE ROTATE A
*  -----------------
*	Faz RR na stack A e imprime "rra"
*/
void	do_rra(t_stack **stack_a)
{
	rrotate(stack_a);
	ft_putstr("rra\n");
}

/* -----------------
*   REVERSE ROTATE B
*  -----------------
*	Faz RR na stack A e imprime "rrb"
*/
void	do_rrb(t_stack **stack_b)
{
	rrotate(stack_b);
	ft_putstr("rrb\n");
}

/* ----------------------
*   REVERSE ROTATE A & B
*  ----------------------
*	Faz RR na stack A e na stack B e imprime "rrr"
*/
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_putstr("rrr\n");
}
