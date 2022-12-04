/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:41:11 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 12:20:40 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

/*  -----------------
*	NBR_CMP
*	-----------------
*   Compara duas strings de digitos para verificar se sao iguais ou nao.
*   Se uma das strings comeca com um +, e ignorada e o resto
*   da string de numeros e verificada
*   Exemplo:
*	+123 == 123 mas -123 != 123.
*   Retorna 0 se as strings derem match ou outro valor se nao.
*/
int	nbr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
