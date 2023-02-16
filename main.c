#include "push_swap.h"

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
