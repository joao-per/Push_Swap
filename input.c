/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:24:21 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/01 17:24:21 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ifnb(int ac, char **nb)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (nb[i][j])
		{
			if (j == 0 && (nb[i][j] == '-' || nb[i][j] == '+'))
				j++;
			if ((nb[i][j] >= '0' && nb[i][j] <= '9'))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_dup(char **nb)
{
	int	i;
	int	j;

	i = 0;
	while (nb[++i])
	{
		j = i + 1 - 1;
		while (nb[++j])
		{
			if (ft_atol(nb[i]) == ft_atol(nb[j]))
				return (1);
		}
	}
	return (0);
}

int	check_limits(int ac, char **nb)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atol(nb[i]) == 6969696969)
			return (1);
	}
	return (0);
}

int	check_input(int ac, char **nb)
{
	if (!check_ifnb(ac, nb))
		return (0);
	if (check_limits(ac, nb))
		return (0);
	if (check_dup(nb))
		return (0);
	return (1);
}
