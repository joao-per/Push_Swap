/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:25:54 by joao-per          #+#    #+#             */
/*   Updated: 2023/02/23 21:25:55 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenz(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

int	find_nl_clean(char *resto)
{
	int	i;
	int	j;
	int	new_line;

	i = 0;
	j = 0;
	new_line = 0;
	while (resto[i])
	{
		if (new_line)
			resto[j++] = resto[i];
		if (resto[i] == '\n')
			new_line = 1;
		resto[i] = '\0';
		i++;
	}
	return (new_line);
}

char	*ft_strjoin(char *line, char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlenz(line) + ft_strlenz(buff) + 1);
	if (!str)
		return (NULL);
	while (line && line[j])
		str[i++] = line[j++];
	j = 0;
	while (buff && buff[j])
	{
		str[i] = buff[j++];
		if (str[i++] == '\n')
			break ;
	}
	str[i] = '\0';
	free (line);
	return (str);
}
