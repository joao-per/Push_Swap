#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				index;
	int				value;
}	t_stack;

/*				CHECKER				*/
static int	check_nb(char *nb);
static int	check_dup(char **nb);
static int	check_zero(char *nb);
int			check_input(char **nb);

/*				UTILS				*/
int			is_digit(char c);

#endif