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
	printf("%.0s\n", "str");
	ft_printf("ft:\n");
	ft_printf("%.0s\n", "str");
	/*unsigned int test;
	for (int i = 0; i < 8; i++)
		test *= 16;
	test--;
	ft_printf("%X\n", test);
	//printf("%X\n", test);*/
	//printf("%#x\n", 420);
	//printf("%p\n", 420);
	/*
	printf("std:\n");
	printf("%.4c\n", 'c');
	printf("%-6.4s\n", "Hello, world!");
	printf("%-06d\n", -12);
	*/
}
