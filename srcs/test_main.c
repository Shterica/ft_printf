#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	str[] = "55";
	/*
	printf("std:\n");
	printf("%2c %2c %2c\n", 'a', 'b', 'c');
	ft_printf("ft:\n");
	ft_printf("%2c %2c %2c\n", 'a', 'b', 'c');
	*/
	printf("std:\n");
	printf("%x\n", 4294967295);
	ft_printf("ft:\n");
	ft_printf("%x\n", 4294967295);
	unsigned int test;
	for (int i = 0; i < 8; i++)
		test *= 16;
	test--;
	ft_printf("%x\n", test);
	printf("%x\n", test);
	/*
	printf("std:\n");
	printf("%.4c\n", 'c');
	printf("%-6.4s\n", "Hello, world!");
	printf("%-06d\n", -12);
	*/
}
