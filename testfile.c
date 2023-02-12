#include "push_swap.h"
#include <stdio.h>

void	push_swap2(int ac, char **av)
{
	char	**strs;

	strs = av + 1;

	printf("Print the av -> %s\n", *strs);
	strs++;
	printf("Print the av -> %s\n", *strs);
	strs++;
	printf("Print the av -> %s\n", *strs);

}
