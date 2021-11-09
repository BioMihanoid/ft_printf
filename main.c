#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int	a;
	int	b;

	a = printf(" %+d ", 9223372036854775807LL);
	printf("\n");
	b = ft_printf(" %+d ", 9223372036854775807LL);
	printf ("\na - %d\nb - %d\n", a, b);
	return (0);
}