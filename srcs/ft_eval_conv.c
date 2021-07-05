#include "ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->tl += write(1, &c, 1);
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
	(void) tab;
}

void	ft_print_unsigned_int(t_print *tab)
{
	(void) tab;
}
