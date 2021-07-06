#include "ft_printf.h"
#include "libft.h"

int	ft_eval_width(t_print *tab, const char *format, int pos)
{
	int	len;

	tab->wdt = ft_atoi(format + pos);
	len = ft_numlen(tab->wdt);
	pos = pos + len;
	return (pos);
}

int	ft_flag_dash(t_print *tab, const char *format, int pos)
{
	(void) format;
	pos++;
	tab->dash = 1;
	return (pos);
}

int	ft_flag_zero(t_print *tab, const char *format, int pos)
{
	(void) format;
	pos++;
	tab->zero = 1;
	return (pos);
}

int	ft_flag_point(t_print *tab, const char *format, int pos)
{
	tab->pnt = 1;
	pos++;
	if (ft_isdigit(format[pos]))
	{
		tab->prc = ft_atoi(format + pos);
		pos += ft_numlen(tab->prc);
	}
	else if (format[pos] == '*')
	{
		tab->prc = va_arg(tab->args, int);
		pos++;
	}
	return (pos);
}

int	ft_flag_star(t_print *tab, const char *format, int pos)
{
	(void) format;
	tab->wdt = va_arg(tab->args, int);
	pos++;
	return (pos);
}
