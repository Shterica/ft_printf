#include "libft.h"

int	ft_numlen(long int nb, int base_len)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / base_len;
		i++;
	}
	return (i);
}
