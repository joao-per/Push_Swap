/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:00:16 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/30 12:24:08 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
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

/*  -----------------
*	PUSH_SWAP
*	-----------------
*	DESCRIÇÃO
*	Escolhe o método para sortear, dependendo da quantidade de números
*	VARIÁVEIS
*	#1. Stack A
*	#2. Stack B
*	#3. O tamanho da stack*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !sort_checker(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		self_esteem(stack_a);
	else if (stack_size > 3 && !sort_checker(*stack_a))
		sort(stack_a, stack_b);
}

/*  -----------------
*	MAIN
*	-----------------
*	DESCRIÇÃO
*	Verifica se o input é correto, inicializa as stacks e sorteia.
*	Quando o sorting acabar, dá free às stacks e sai da função*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!input_checker(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	set_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
