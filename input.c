#include "push_swap.h"

static int	check_nb(char *nb)
{
	int	i;

	i = 0;
	if(nb[i + 1] != '\0' && (nb[i] == '+' || nb[i] == '-'))
		i++;
	while (nb[i] >= '0' && nb[i] <='9' && nb[i])
		i++;
	if (nb[i] != '\0' && !is_digit(nb[i]))
		return (0);
	return (1);
}
