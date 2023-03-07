/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:39:36 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/07 10:41:46 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

void	do_pushz(t_stack **stack_a, t_stack **stack_b, char *op);
void	do_swapz(t_stack **stack_a, t_stack **stack_b, char *op);
void	do_rotatez(t_stack **stack_a, t_stack **stack_b, char *op);
void	do_rrotatez(t_stack **stack_a, t_stack **stack_b, char *op);

#endif