#include "ft_printf.h"
#include "libft.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->prc = 0;
	ft_update_tab(tab, 1);
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
	tab->tl += write(1, &c, 1);
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}

void	ft_print_str(t_print *tab)
{
	(void) tab;
}

void	ft_print_pointer(t_print *tab)
{
	(void) tab;
}

void	ft_print_int(t_print *tab)
{
	int	nb;
	int	len;
	char	al;
	char	*nbr;
	int	i;

	nb = va_arg(tab->args, int);
	if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
		return ;
	i = 0;
	if (nb < 0)
	{
		tab->sign = 1;
		i++;
	}
	nbr = ft_itoa(nb);
	if (!nbr)
		return ;
	len = ft_strlen(nbr);
	ft_update_tab(tab, len);
	if (tab->zero && tab->sign)
		tab->tl += write(1, "-", 1);
	if (tab->zero)
		al = '0';
	else
		al = ' ';
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, &al, 1);
	if (!tab->zero && tab->sign)
		tab->tl += write(1, "-", 1);
	while (tab->prc-- > 0)
		tab->tl += write(1, "0", 1);
	while (nbr[i])
		tab->tl += write(1, num + i++, 1);
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
	free(nbr);
}

void	ft_print_unsigned_int(t_print *tab)
{
	(void) tab;
}
