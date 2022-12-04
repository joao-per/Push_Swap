/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:11:11 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 10:28:03 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/*  ------------------------
*    PUSH_ALL_SAVE_THREE
*	------------------------
*	Leva todos os elementos da stack A para a stack B,
*	menos os três últimos.
*	Primeiro dá push aos elementos menores, 
*	e depois os maiores para ajudar na ordenação.
*/
static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/*  ---------------
*    SHIFT_STACK
*	---------------
*	Depois que a maior parte da stack é ordenada,
*	desloca a stack A até que o valor menor esteja no topo.
*	Se estiver na metade inferior da stack, dá reverese rotate, 
*	caso contrário, dá rotate até que esteja no topo da stack.
*/
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_minor_index_pos(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

/*  ----------
*    SORT
*	----------
*	Algorítmo para stacks maiores de 3:
*		-	Dá push a todos os elementos menos os 3 ultimos, para a stack B.
*		-	Ordena os 3 úlitmos números na stack A.
*		-	Calcula a função a realizar de modo
*a gastar o menor número de moves possíveis.
*		-	Troca os elementos até a Stack A estiver organizada.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	self_esteem(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!sort_checker(*stack_a))
		shift_stack(stack_a);
}
