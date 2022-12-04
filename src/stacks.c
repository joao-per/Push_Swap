/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:11:08 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 10:15:36 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/* -----------------
*	GET_BOTTOM_VALUE
*  -----------------
*	Retorna o último valor da stack
*/
t_stack	*get_bottom_value(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* ----------------------
*	GET_PENULTIMO_VALUE
*  ----------------------
*	O que é que achas que faz? lol
*/
t_stack	*get_penultimo_value(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/* -----------------
*	GET_STACK_SIZE
*  -----------------
*	Retorna o número de elementos numa stack-
*/
int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/* -----------------
*	NEW_STACK
*  -----------------
*	Cria uma nova stack com o valor dado e retorna-a.
*/
t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/* -----------------
*   STACK_ADD_BOTTOM
*  -----------------
*	Adiciona um novo elemento no fim da stack
*/
void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_bottom_value(*stack);
	tail->next = new;
}
