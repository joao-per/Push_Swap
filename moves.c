#include "push_swap.h"

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
	if (cost_a > 0 && cost_b > 0)
		rotate_stack(a, b, &cost_a, &cost_b, "rr");
	else if (cost_a < 0 && cost_b < 0)
		do_rotate_both(a, b, &cost_a, &cost_b, "rrr");
	rotate_stack(a, b, &cost_a, &cost_b, "rstack");
	do_push(a, b, "pa");
}
