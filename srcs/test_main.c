#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("std:\n");
	printf("%c %c %c\n", 'a', 'b', 'c');
	ft_printf("ft:\n");
	ft_printf("%c %c %c\n", 'a', 'b', 'c');
}
