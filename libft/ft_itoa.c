#include "libft.h"

static int	ft_intlen(int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nb;
	char		*p;

	nb = n;
	i = ft_intlen(n);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	p[i--] = '\0';
	if (nb == 0)
		p[0] = 48;
	if (nb < 0)
	{
		p[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		p[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (p);
}
