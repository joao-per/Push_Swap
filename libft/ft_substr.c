/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:24:54 by joao-per          #+#    #+#             */
/*   Updated: 2023/01/25 13:24:54 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	size_t	b;
	char	*substring;

	b = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substring = malloc(sizeof(char));
		*substring = '\0';
		return (substring);
	}
	a = ft_strlen(s + start);
	if (len > a)
		len = a;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (start < ft_strlen(s) && b < len)
		substring[b++] = s[start++];
	substring[b] = '\0';
	return (substring);
}
