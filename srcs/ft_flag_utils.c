#include "ft_printf.h"

void	ft_update_tab(t_print *tab, int len)
{
	if (tab->prc)
		tab->zero = 0;
	if (tab->wdt <= tab->prc || tab->wdt <= len)
		tab->wdt = 0;
	else
		tab->wdt -= tab->prc;
	if (tab->prc <= len)
		tab->prc = 0;
	else
		tab->prc -= len;
}
