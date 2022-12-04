/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:58:08 by joao-per          #+#    #+#             */
/*   Updated: 2022/09/19 19:27:48 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*connect;

	connect = (t_list *)malloc(sizeof(t_list));
	if (!connect)
		return (NULL);
	connect->content = (void *)content;
	connect->next = NULL;
	return (connect);
}
