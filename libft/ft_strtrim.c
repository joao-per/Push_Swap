/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:23:39 by joao-per          #+#    #+#             */
/*   Updated: 2022/09/19 19:28:56 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	i;

	if (!s || !set)
		return (0);
	while (*s && ft_strchr(set, *s))
		s++;
	i = ft_strlen(s);
	while (i && ft_strchr(set, s[i]))
		i--;
	return (ft_substr(s, 0, i + 1));
}
