/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:11:34 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 10:15:22 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/*	-------------
*    GET_COST
*	-------------
*	Calcula o custo de mover cada elemento na stack B para a correta 
*	posição da stack A.
*	Os dois custos são calculados:
*		cost_b representa o custo de obter o elemento para o topo da stack B.
*		cost_a representa o custo de o obter para a posição correta na stack A.
*	Se o elemento na metade estiver na metade inferior da stack, 
*	o custo vai ser negativo, caso contrário será positivo.
*/
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = get_stack_size(temp_a);
	size_b = get_stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

/*  --------------------
*	DO_CHEAPEST_MOVE
*	--------------------
*	Encontra o elemento na stack B com o custo mais barato
*	para o mover para a stack A
*	e move-o para a posição correta na stack A.
*/
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (abs_vl(temp->cost_a) + abs_vl(temp->cost_b) < abs_vl(cheapest))
		{
			cheapest = abs_vl(temp->cost_b) + abs_vl(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
