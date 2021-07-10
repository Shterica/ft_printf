#include "ft_printf.h"

int	ft_flag_hash(t_print *tab, const char *format, int pos)
{
	(void) format;
	pos++;
	tab->hash = 1;
	return (pos);
}

int	ft_flag_space(t_print *tab, const char *format, int pos)
{
	(void) format;
	pos++;
	tab->sp = 1;
	return (pos);
}

int	ft_flag_plus(t_print *tab, const char *format, int pos)
{
	(void) format;
	pos++;
	tab->plus = 1;
	return (pos);
}