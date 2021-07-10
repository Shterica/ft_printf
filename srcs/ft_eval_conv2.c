#include "ft_printf.h"
#include "libft.h"

void	ft_print_hex(t_print *tab, unsigned long int nb)
{
	int	len;
	char	al;

	if (!nb)
	{
		ft_putchar_fd('0', 1);
		tab->tl += 1;
		return ;
	}
	len = ft_numlen(nb, 16);
	if (tab->hash)
		len += 2;
	ft_update_tab(tab, len);
	if (tab->zero && tab->hash)
		tab->tl += write(1, tab->prefix, 2);
	if (tab->zero)
		al = '0';
	else
		al = ' ';
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, &al, 1);
	if (!tab->zero && tab->hash)
		tab->tl += write(1, tab->prefix, 2);
	while (tab->prc-- > 0)
		tab->tl += write(1, "0", 1);
	ft_putnbr_hex(nb, tab->base);
	tab->tl += len;
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}
void	ft_print_hex_low(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	ft_strcpy(tab->base, "0123456789abcdef");
	ft_strcpy(tab->prefix, "0x");
	ft_print_hex(tab, nb);
}

void	ft_print_hex_cap(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	ft_strcpy(tab->base, "0123456789ABCDEF");
	ft_strcpy(tab->prefix, "0X");
	ft_print_hex(tab, nb);
}

void	ft_print_percent(t_print *tab)
{
	ft_putchar_fd('%', 1);
	tab->tl++;
}

void	ft_print_pointer(t_print *tab)
{
	unsigned long int	nb;

	nb = (unsigned long int)va_arg(tab->args, void *);
	tab->hash = 1;
	ft_strcpy(tab->base, "0123456789abcdef");
	ft_strcpy(tab->prefix, "0x");
	ft_print_hex(tab, nb);
}
