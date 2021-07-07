#include "ft_printf.h"
#include "libft.h"

void	ft_print_hex_low(t_print *tab)
{
	(void) tab;
}

void	ft_print_hex_cap(t_print *tab)
{
	(void) tab;
}

void	ft_print_percent(t_print *tab)
{
	ft_putchar_fd('%', 1);
	tab->tl++;
}

void	ft_print_pointer(t_print *tab)
{
	(void) tab;
}
