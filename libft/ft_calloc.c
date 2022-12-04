/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 03:27:22 by joao-per          #+#    #+#             */
/*   Updated: 2022/09/19 19:26:52 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*fakemalloc;

	fakemalloc = malloc(count * size);
	if (!fakemalloc)
		return (NULL);
	ft_memset(fakemalloc, '\0', (count * size));
	return (fakemalloc);
}
