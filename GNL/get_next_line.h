/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:26:12 by joao-per          #+#    #+#             */
/*   Updated: 2023/02/23 21:26:12 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*				UTILS				*/
size_t	ft_strlenz(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		find_nl_clean(char *str);
/*				MAIN				*/
char	*get_next_line(int fd);

#endif