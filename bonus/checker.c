/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:51:30 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/07 09:51:30 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../GNL/get_next_line.h"
#include "checker.h"

int	if_statements(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		do_pushz(a, b, "pa");
	else if (!ft_strcmp(cmd, "pb\n"))
		do_pushz(a, b, "pb");
	else if (!ft_strcmp(cmd, "sa\n"))
		do_swapz(a, b, "sa");
	else if (!ft_strcmp(cmd, "sb\n"))
		do_swapz(a, b, "sb");
	else if (!ft_strcmp(cmd, "ss\n"))
		do_swapz(a, b, "ss");
	else if (!ft_strcmp(cmd, "ra\n"))
		do_rotatez(a, b, "ra");
	else if (!ft_strcmp(cmd, "rb\n"))
		do_rotatez(a, b, "rb");
	else if (!ft_strcmp(cmd, "rr\n"))
		do_rotatez(a, b, "rr");
	else if (!ft_strcmp(cmd, "rra\n"))
		do_rrotatez(a, b, "rra");
	else if (!ft_strcmp(cmd, "rrb\n"))
		do_rrotatez(a, b, "rrb");
	else if (!ft_strcmp(cmd, "rrr\n"))
		do_rrotatez(a, b, "rrr");
	else
		return (0);
	return (1);
}

void	display_result(t_stack **a)
{
	if (check_order(a) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*cmd;

	if (ac < 2)
		return (0);
	a = create_list(ac, av);
	b = NULL;
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		if (!ft_strcmp(cmd, "\n"))
			break ;
		if (!if_statements(&a, &b, cmd))
			freexit(&a, &b);
		free(cmd);
	}
	free(cmd);
	display_result(&a);
	lstclear(&a);
	lstclear(&b);
}
