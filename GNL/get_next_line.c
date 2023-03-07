/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:25:45 by joao-per          #+#    #+#             */
/*   Updated: 2023/02/23 21:25:45 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	resto[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (resto[fd][0] || read(fd, resto[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, resto[fd]);
		if (ft_strlenz(resto[fd]) == 0)
			return (line);
		if (find_nl_clean(resto[fd]) == 1)
			break ;
		if (read(fd, resto[fd], 0) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}

/* #include <fcntl.h>
int	main(void)
{
	char	*line;
	int	i;
	int	text1;

	text1 = open("test/test.txt", O_RDONLY);
	i = 1;

	while(i < 4)
	{
		line = get_next_line(text1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(text1);
	return (0);
} */