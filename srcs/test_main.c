#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("%7.5s", "yolo");
		printf("\n");
		ft_printf("%7.5s", "yolo");
		ft_printf("\n");
		printf("%.09s", "hi low");
		printf("\n");
		ft_printf("%.09s", "hi low");
		ft_printf("\n");
		return (0);
	}
	else if (av[1][0] == 'd')
	{
		printf("std:\n");
		printf((const char *) av[2], atoi(av[3]));
		printf("\n");
		ft_printf("ft:\n");
		ft_printf((const char *) av[2], atoi(av[3]));
		ft_printf("\n");
	}
	else if (av[1][0] == 's')
	{
		printf("std:\n");
		printf((const char *) av[2], av[3]);
		printf("\n");
		ft_printf("ft:\n");
		ft_printf((const char *) av[2], av[3]);
		ft_printf("\n");
	}
	else if (av[1][0] == 'c')
	{
		printf("std:\n");
		printf((const char *) av[2], av[3][0]);
		printf("\n");
		ft_printf("ft:\n");
		ft_printf((const char *) av[2], av[3][0]);
		ft_printf("\n");
	}
}
