#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;
	int	ret;
	t_print	*tab;

	tab = (t_print *) malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_eval_format(tab, format, i + 1);
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	ret += tab->tl;
	va_end(tab->args);
	free(tab);
	return (ret);
}
