/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:13:51 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/05 11:13:51 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atol(const char *str)
{
	long int	result;
	int			i;
	int			negative;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	if (result > INT_MAX || result < -2147483648)
		return (69696969);
	return (result * negative);
}
