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
	char	*str;
	int	i;
	int	len;

	i = 0;
	str = va_arg(tab->args, char *);
	len = ft_strlen(str);
	if (!tab->pnt)
		tab->prc = len;
	ft_update_tab(tab, 0);
	if (!tab->dash)
		while(tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
	while (i < tab->prc && str[i])
		tab->tl += write(1, &str[i++], 1);
	if (tab->dash)
		while(tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}

void	ft_print_int(t_print *tab)
{
	int	nb;
	int	len;
	char	al;
	char	*nbr;
	int	i;

	nb = va_arg(tab->args, int);
	//if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
	//	return (ft_print_zero(tab));
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
		tab->tl += write(1, &nbr[i++], 1);
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
	free(nbr);
}

void	ft_putnbr_un(unsigned int nb)
{
	if (nb < 10)
		ft_putchar_fd(nb + '0', 1);
	else
	{
		ft_putnbr_un(nb / 10);
		ft_putchar_fd(nb % 10 + '0', 1);
	}
}

void	ft_print_unsigned_int(t_print *tab)
{
	unsigned int	nb;
	int		len;
	char		al;

	nb = va_arg(tab->args, unsigned int);
	len = ft_numlen(nb);
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
	ft_putnbr_un(nb);
	tab->tl += len;
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}
