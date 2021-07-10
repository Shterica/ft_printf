#include "ft_printf.h"
#include "libft.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->prc = 0;
	tab->hash = 0;
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
	int		i;
	int		len;

	i = 0;
	str = va_arg(tab->args, char *);
	if (!str)
		return ;
	len = ft_strlen(str);
	if (tab->pnt)
	{
		len = ft_min(len, tab->prc);
		tab->prc = 0;
	}
	tab->hash = 0;
	ft_update_tab(tab, len);
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
	while (i < len && str[i])
		tab->tl += write(1, &str[i++], 1);
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}

void	ft_print_int(t_print *tab)
{
	int		i;
	int		nb;
	int		len;
	char	*nbr;

	nb = va_arg(tab->args, int);
	if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
		return (ft_print_empty(tab));
	nbr = ft_itoa(nb);
	if (!nbr)
		return ;
	len = ft_strlen(nbr);
	tab->hash = 0;
	i = 0;
	if (nb < 0)
	{
		tab->sign = 1;
		i++;
	}
	ft_update_tab(tab, len);
	ft_print_nbr_left(tab);
	while (nbr[i])
		tab->tl += write(1, &nbr[i++], 1);
	free(nbr);
	ft_print_nbr_right(tab);
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
	int				len;

	nb = va_arg(tab->args, unsigned int);
	if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
		return (ft_print_empty(tab));
	len = ft_numlen(nb, 10);
	tab->hash = 0;
	ft_update_tab(tab, len);
	ft_print_nbr_left(tab);
	ft_putnbr_un(nb);
	tab->tl += len;
	ft_print_nbr_right(tab);
}
