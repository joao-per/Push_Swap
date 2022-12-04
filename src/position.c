/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:36:04 by joao-per          #+#    #+#             */
/*   Updated: 2022/11/29 10:45:45 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

/*  ----------
*    GET_POS
*	----------
*	Atribui uma posição a cada valor na stack, começando na superior.
*	Exemplo:
*		valores:	 3	 0	 9	 1
*		indexes:	[3]	[1]	[4]	[2]
*		posição:	 0º	 1º	 2º	 3º
*	Esta função é usada para calcular o custo de mover um número para
*	uma certa posição. Se o exemplo acima for a stack B, iria custar 0
*	para dar push
*	do primeiro elemento para a stack A. No entanto, se quisermos dar
*	push do maior valor (9), que está na 3ª posição, ia custar 2 moves
*	para trazer o 9 para o topo da stack antes de dar push para a stack A.
*/
static void	get_pos(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

/*  -------------------
*    GET_MINOR_INDEX
*	-------------------
*	Retorna a posição do valor com o menor index (menor número).
*/
int	get_minor_index_pos(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		lowest_pos;

	temp = *stack;
	lowest_index = INT_MAX;
	get_pos(stack);
	lowest_pos = temp->pos;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (lowest_pos);
}

/*  -------------
*    GET_TARGET
*	-------------
*	Escolhe a melhor posição de destino na stack A para o index de
* 	um elemento na stack B. Primeiro verifica se o index do elemento B pode
* 	ser colocado em algum lugar entre os elementos na stack A, verificando se
* 	existe um elemento na stack A com um index maior. Se não, ele encontra o
* 	elemento com o menor index em A e o atribui como a posição de destino.
*	Exemplo:
*		target_pos começa no INT_MAX
*		B index: 3
*		A stack (indexes): 9 4 2 1 0
*		9 > 3 && 9 < INT_MAX 	: target_pos atualizada para 9
*		4 > 3 && 4 < 9 			: target_pos atualizada para 4
*		2 < 3 && 2 < 4			: não há alterações.
*	Então target_pos precisa de estar na posição do index 4, visto
*	que é o index mais próximo.
*	Exemplo:
*		target_pos começa no INT_MAX
*		B index: 20
*		A stack (indexes): 16 4 3
*		16 < 20					: não há alterações. target_pos = INT_MAX
*		4  < 20					: não há alterações.
*		3  < 20					: não há alterações.
*	... target_pos continua no INT_MAX, é necessário mudar a estratégia.
*		16 < 20					: target_pos atualizada para 20
*		4  < 20					: target_pos atualizada para 4
*		3  < 20					: target_pos atualizada para 3
*	Então target_pos precisa de estar na posição do index 3, visto
*	que é o fim da stack.
*/
static int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index > b_idx && temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

/*  -----------------
*    GET_TARGET_POS
*	-----------------
*	Atribui ao destino uma posição na stack A para cada elemento da stack A.
*	A posição do destino é o sítio que o elemento em B precisa de
*	obter para conseguir ser ordenado corretamente. Esta posição vai
*	ser usada para calcular o custo de mover cada elemento
*	para a posição do seu destino na stack A.
*/
void	get_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		target_pos;

	temp_b = *b;
	get_pos(a);
	get_pos(b);
	target_pos = 0;
	while (temp_b)
	{
		target_pos = get_target(a, temp_b->index, INT_MAX, target_pos);
		temp_b->target_pos = target_pos;
		temp_b = temp_b->next;
	}
}
