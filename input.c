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

static int	check_dup(char **nb)
{
	int	i;
	int j;

	i = 1;
	while (nb[i])
	{
		j = 1;
		while(nb[j])
		{
			if (nbr_cmp(nb[i], nb[j]) == 0 && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	check_input(char **av)
{
	int	i;
	int	only_zero;

	only_zero = 0;
	i = 1;
	while (av[i])
	{
		if (!check_nb(av[i]))
			return (0);
		only_zero += check_zero(av[i]);
		i++;
	}
	if (only_zero> 1)
		return (0);
	if (check_dup(av))
		return (0);
	return (1);
}
