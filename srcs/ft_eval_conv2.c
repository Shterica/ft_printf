#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_hex(unsigned int nb, char *base)
{
	unsigned int	base_len;

	base_len = 16;
	if (nb < base_len)
		ft_putchar_fd(base[nb], 1);
	else
	{
		ft_putnbr_hex(nb / base_len, base);
		ft_putchar_fd(base[nb % base_len], 1);
	}
}

void	ft_print_hex_low(t_print *tab)
{
	int	len;
	char	al;
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	if (!nb)
	{
		ft_putchar_fd('0', 1);
		tab->tl += 1;
		return ;
	}
	len = ft_numlen(nb, 16);
	ft_update_tab(tab, len);
	if (tab->zero)
		al = '0';
	else
		al = ' ';
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, &al, 1);
	while (tab->prc-- > 0)
		tab->tl += write(1, "0", 1);
	ft_putnbr_hex(nb, "0123456789abcdef");
	tab->tl += len;
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}

void	ft_print_hex_cap(t_print *tab)
{
	int	len;
	char	al;
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	if (!nb)
	{
		ft_putchar_fd('0', 1);
		tab->tl += 1;
		return ;
	}
	len = ft_numlen(nb, 16);
	ft_update_tab(tab, len);
	if (tab->zero)
		al = '0';
	else
		al = ' ';
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, &al, 1);
	while (tab->prc-- > 0)
		tab->tl += write(1, "0", 1);
	ft_putnbr_hex(nb, "0123456789ABCDEF");
	tab->tl += len;
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}

void	ft_print_percent(t_print *tab)
{
	ft_putchar_fd('%', 1);
	tab->tl++;
}

void	ft_print_pointer(t_print *tab)
{
	(void) tab;
}
