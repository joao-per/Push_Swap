/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:11:39 by joao-per          #+#    #+#             */
/*   Updated: 2022/12/03 00:17:01 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/* -----------------
*   NUMBER_CHECKER
*  -----------------
*   Verifica se o argumento é um número, quer seja positivo/negativo.
*/
static int	number_checker(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* --------------------
*	DUPLICATES_CHECKER
*  --------------------
*   Verifica se existem números duplicados
*   Retorna 1 se encontrar duplicados.
*/
static int	duplicates_checker(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* -----------------
*	ZERO_CHECKER
*  -----------------
*   Verifica se o argumento é 0 para evitar:
*	0, 0000 +00 -00000 duplicados pois todos estes valores são 0.
*	Retorna 1 se o argumento possuir apenas 0s.*/
static int	zero_checker(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/* -----------------
*	INPUT_CHECKER
*  -----------------
*   Verifica todas as condições anteriores.
*   Retorna 1 se o input for válido.
*/
int	input_checker(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!number_checker(av[i]))
			return (0);
		nb_zeros += zero_checker(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (duplicates_checker(av))
		return (0);
	return (1);
}
