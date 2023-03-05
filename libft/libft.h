/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:24:48 by joao-per          #+#    #+#             */
/*   Updated: 2023/01/25 13:24:48 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_atol(const char *str);
int		is_digit(int i);
void	ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *str);
int		neg_to_pos(int nb);
int		is_sign(char c);

#endif