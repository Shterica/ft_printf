#include "libft.h"

int	ft_numlen(long int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
