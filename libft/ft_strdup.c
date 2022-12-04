/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:23:03 by joao-per          #+#    #+#             */
/*   Updated: 2022/09/19 19:28:26 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*novo;
	int		i;

	i = 0;
	novo = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (novo == NULL)
		return (0);
	while (*s)
		novo[i++] = *s++;
	novo[i] = '\0';
	return (novo);
}
