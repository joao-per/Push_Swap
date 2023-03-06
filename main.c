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

/* void	create_list(int ac, char **av, t_stack **stack)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		add_back(stack, new_node(ft_atoi(av[i])));
		i++;
	}
} */

t_stack	*fill_stack_nbs(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			freexit(&stack_a, NULL);
		if (i == 1)
			stack_a = new_stack((int)nb);
		else
			add_back(&stack_a, new_stack((int)nb));
		i++;
	}
	return (stack_a);
}

int	check_order(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->number < temp->next->number)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

static void	sorts(t_stack **stack_a, t_stack **stack_b, int size)
{
	set_index(*stack_a, size + 1);
	if (!check_order(*stack_a))
	{
		if (size == 2)
			do_swap(stack_a, stack_b, "sa");
		else if (size == 3)
			sort_three(stack_a, stack_b);
		else
			sort(stack_a, stack_b);
	}
}

void	printstack(t_stack **stack_a)
{
	t_stack	*head;

	head = *stack_a;
	printf("Stack A: \n");
	while (head)
	{
		printf("%d\n", head->number);
		head = head->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (ac < 2)
		return (0);
	if (!check_input(av))
		freexit(NULL, NULL);
	stack_a = fill_stack_nbs(ac, av);
	stack_b = NULL;
	size = lstsize(stack_a);
	sorts(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
	//printstack(&stack_a);
