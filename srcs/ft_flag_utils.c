#include "ft_printf.h"
#include "libft.h"

void	ft_update_prefix(t_print *tab)
{
	if (tab->hash)
		tab->wdt -= 2;
	else if (tab->sign)
	{
		ft_strcpy(tab->prefix, "-");
		tab->wdt--;
	}
	else if (tab->plus)
	{
		ft_strcpy(tab->prefix, "+");
		tab->wdt--;
	}
	else if (tab->sp)
	{
		ft_strcpy(tab->prefix, " ");
		tab->wdt--;
	}
}

void	ft_update_tab(t_print *tab, int len)
{
	ft_update_prefix(tab);
	if (tab->pnt)
		tab->zero = 0;
	if (tab->wdt <= tab->prc || tab->wdt <= len)
		tab->wdt = 0;
	else if (tab->prc > len)
		tab->wdt -= tab->prc;
	else
		tab->wdt -= len;
	if (tab->prc <= len)
		tab->prc = 0;
	else
		tab->prc -= len;
}
