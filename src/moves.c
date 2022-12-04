/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:50:03 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 10:46:48 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/*  ---------------------------
*    DO REVERESE ROTATE BOTH
*	-------------------------
*	Dá reverse em ambas as stacks até que uma delas esteja em posição.
*	O custo dado é negativo, pois ambas as posições estão na metade inferior
* 	das stacks. O custo aumenta à medida que as stacks são
* 	percorridas, quando chega a 0, a stack foi girada o máximo possível
*	e a posição superior está correta.
*/
static void	do_rrotate_both(t_stack **a, t_stack **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/*  ----------------------
*    DO ROTATE BOTH
*	----------------------
*	Gira a stack A e B até que uma delas fique em posição
*	O custo dado é positivo pois ambas as posições estão na
*	metade acima das stacks. O custo é diminuído enquanto as stacks são giradas,
*	quando chega a 0, a stack foi girada o máximo possível
*	e a posição superior está correta.
*/
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/*  ----------------------
*    DO ROTATE A
*	----------------------
*	Gira a stack A até esta estar na posição correta. Se o custo for
*	negativo, a stack vai ser girada ao contrário, se positivo, girada normalmente
*/
static void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/*  ------------------
*    DO ROTATE B
*	------------------
*	Gira a stack B até esta estar na posição correta. Se o custo for
*	negativo, a stack vai ser girada ao contrário, se positivo, girada normalmente
*/
static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/*  ------------------
*    DO MOVE
*	------------------
*	Escolha que move fazer para ter o stack B na posição correta de A
*	Se os custos de mover as stacks A e B para a posições corretas
*	(ou seja, ambos negativos de ambos positivos),
*	ambos serão girados ou girados ao contrário ao mesmo tempo.
*	Eles também podem ser girados separadamente, antes de finalmente
*	empurrar o elemento B superior para a stack superior A.
*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}
