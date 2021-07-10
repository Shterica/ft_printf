#include "libft.h"

void	ft_putnbr_hex(unsigned long int nb, const char *base)
{
	unsigned long int	base_len;

	base_len = 16;
	if (nb < base_len)
		ft_putchar_fd(base[nb], 1);
	else
	{
		ft_putnbr_hex(nb / base_len, base);
		ft_putchar_fd(base[nb % base_len], 1);
	}
}
