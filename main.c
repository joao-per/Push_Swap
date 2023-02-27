#include "push_swap.h"

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
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = new_stack((int)nb);
		else
			stack_add_bottom(&stack_a, new_stack((int)nb));
		i++;
	}
	return (stack_a);
}

static void	sorts(t_stack **stack_a, t_stack **stack_b, int size)
{
	if(!sort_checker(*stack_a))
	{
		if (size == 2)
			do_sa(stack_a);
		else if (size == 3)
			sort_three(stack_a, stack_b);
		else
			sort(stack_a, stack_b);
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
		exit_error(NULL, NULL);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
