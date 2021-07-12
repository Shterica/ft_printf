#include "ft_printf.h"
#include "libft.h"

void	ft_print_hex(t_print *tab, unsigned long int nb)
{
	int	len;

	if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
		return (ft_print_empty(tab));
	len = ft_numlen(nb, 16);
	ft_update_tab(tab, len);
	ft_print_nbr_left(tab);
	ft_putnbr_hex(nb, tab->base);
	tab->tl += len;
	ft_print_nbr_right(tab);
}

void	ft_print_hex_low(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	ft_strcpy(tab->base, "0123456789abcdef");
	if (nb == 0)
		tab->hash = 0;
	if (tab->hash)
		ft_strcpy(tab->prefix, "0x");
	ft_print_hex(tab, nb);
}

void	ft_print_hex_cap(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	ft_strcpy(tab->base, "0123456789ABCDEF");
	if (nb == 0)
		tab->hash = 0;
	if (tab->hash)
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
	if (nb != 0 || OS == 0)
		tab->hash = 1;
	else
		tab->hash = 0;
	ft_strcpy(tab->base, "0123456789abcdef");
	if (tab->hash)
		ft_strcpy(tab->prefix, "0x");
	ft_print_hex(tab, nb);
}
