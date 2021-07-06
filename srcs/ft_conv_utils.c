#include "ft_printf.h"

void	ft_allign(t_print *tab, int len)
{
	char c;
	
	if (tab->zero)
		c = '0';
	else
		c = ' ';
	while (len-- > 0)
		tab->tl += write(1, &c, 1);
}
