#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\f' || c == '\n' || c == '\r'\
			|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nbr)
{	
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(nbr[i]) == 1)
		i++;
	if (nbr[i] == '-' || nbr [i] == '+')
	{
		if (nbr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(nbr[i]) == 1)
	{
		res = res * 10 + (nbr[i] - 48);
		i++;
	}
	return (res * sign);
}
