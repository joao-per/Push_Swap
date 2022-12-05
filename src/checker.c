/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:35:20 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 21:35:20 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/get_next_line.h"
#include "../includes/push_swap.h"

int	if_statements(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		do_pa(a, b);
	else if (!ft_strcmp(cmd, "pb\n"))
		do_pb(a, b);
	else if (!ft_strcmp(cmd, "sa\n"))
		do_sa(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		do_sb(b);
	else if (!ft_strcmp(cmd, "ss\n"))
		do_ss(a, b);
	else if (!ft_strcmp(cmd, "ra\n"))
		do_ra(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		do_rb(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		do_rr(a, b);
	else if (!ft_strcmp(cmd, "rra\n"))
		do_rra(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		do_rrb(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		do_rrr(a, b);
	else
		return (0);
	return (1);
}

void	display_result(t_stack *a)
{
	if (sort_checker(a) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*b;
	t_stack	*a;
	char	*cmd;

	if (ac < 2)
		return (0);
	b = NULL;
	a = fill_stack_values(ac, av);
	while (1)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (!cmd)
			break ;
		if (!if_statements(&a, &b, cmd))
		{
			free_stack(&b);
			exit_error(&a, &b);
		}
		free(cmd);
	}
	display_result(a);
	free_stack(&b);
	free_stack(&a);
}
