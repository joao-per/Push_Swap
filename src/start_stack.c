/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:35:32 by joao-per          #+#    #+#             */
/*   Updated: 2022/12/05 12:10:13 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/* -------------------
*	FILL_STACK_VALUES
*	------------------
*	Enche o stack_a com os valores dados nos argumentos.
*	Se ultrapassar o INT_MAX, printa erro e o programa acaba.
*/
t_stack	*fill_stack_values(int ac, char **av)
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
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = new_stack((int)nb);
		else
			stack_add_bottom(&stack_a, new_stack((int)nb));
		i++;
	}
	return (stack_a);
}

/* -------------------
*	SET_INDEX
*	------------------
*	Atribui um index a cada valor na stack A.
*	Desta forma, é possível comparar estes novos "valores" ao contrário
*	dos valore anteriores, que podem ou não ser ajacentes a eles mesmos.
*		ex. valores:		-5	 0	020	 3
*		indexs:				[1]	[2]	[4]	[3]
*	Os Indexes são atríbuídos do maior (tamanho da stack) para o menor (1).
*/
void	set_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
