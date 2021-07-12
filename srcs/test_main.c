#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	//int	ft, std;
	if (ac == 1)
	{
		//printf("out std = %d\n", printf("std: %.*s ", -2, (char *)0));
		//printf("\n");
		ft_printf("out ft  = %d\n", ft_printf("ft : %.*s ", -2, 0));
		ft_printf("\n");
		//printf("std = %d, ft = %d\n", std, ft);
		//std = printf("%.09", "hi low");
		//printf("\n");
		//ft = ft_printf("%.09", "hi low");
		//ft_printf("\n");
		//printf("std = %d, ft = %d\n", std, ft);
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
