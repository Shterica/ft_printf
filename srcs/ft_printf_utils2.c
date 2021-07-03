#include "ft_printf.h"

static int	ft_str_id(const char c_list, char c)
{
	int	i;

	i = 0;
	while (c_list[i] != '\0')
	{
		if (c_list[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_eval_flag(t_print *tab, const char format, int pos)
{
	int	f_id;

	f_id = ft_str_id(tab->flg_list, format[pos]);
	if (f_id != -1)
		pos = tab->flg_eval[f_id](tab, format, pos);
	else if (ft_isdigit(format[pos]))
		pos = ft_eval_width(tab, format, pos);
	//else
	//	pos++;
	return (pos);
}

int	ft_eval_format(t_print *tab, const char *format, int pos)
{
	int	c_id;

	c_id = ft_str_id(tab->cnv_list, format[pos]);
	while (c_id == -1)
	{
		pos = ft_eval_flag(tab, format, pos);
		c_id = ft_str_id(tab->cnv_list, format[pos]);
	}
	tab->cnv_eval[c_id](tab);
	ft_reset_tab(tab);
	return (pos);
}
