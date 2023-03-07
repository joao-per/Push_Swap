/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:25:00 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/01 17:25:00 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorts(t_stack **stack_a, t_stack **stack_b, int size)
{
	set_index(*stack_a, size + 1);
	if (!check_order(stack_a))
	{
		if (size == 2)
			do_swap(stack_a, stack_b, "sa");
		else if (size == 3)
			sort_three(stack_a, stack_b);
		else
		{
			rush_b(stack_a, stack_b);
			while (*stack_b)
			{
				set_best_pos(stack_a, stack_b);
				get_cost(stack_a, stack_b);
				do_cheapest_move(stack_a, stack_b);
			}
			if (!check_order(stack_a))
				fix_order(stack_a, stack_b);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (ac < 2)
		return (0);
	if (!check_input(ac, av))
		freexit(NULL, NULL);
	stack_a = create_list(ac, av);
	stack_b = NULL;
	size = lstsize(stack_a);
	sorts(&stack_a, &stack_b, size);
	lstclear(&stack_a);
	lstclear(&stack_b);
	return (0);
}
