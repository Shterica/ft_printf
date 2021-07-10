#include "ft_printf.h"
#include <stdio.h>

void	ft_update_tab(t_print *tab, int len)
{
	if (tab->hash)
	{
		len -= 2;
		tab->wdt -= 2;
	}
	if (tab->prc)
		tab->zero = 0;
	if (tab->sign)
	{
		tab->wdt--;
		len--;
	}
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
