#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("std:\n");
	printf("%-02c %02c %02c\n", 'a', 'b', 'c');
	ft_printf("ft:\n");
	ft_printf("%2c %2c %2c\n", 'a', 'b', 'c');
	printf("std:\n");
	printf("%.4c\n", 'c');
	printf("%-6.4s\n", "Hello, world!");
	printf("%-06d\n", -12);
}
