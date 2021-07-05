#include "ft_printf.h"
#include "libft.h"

void	ft_reset_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
}

void	ft_config_tab(t_print *tab)
{
	ft_strcpy(tab->cnv_list, "cspdiuxX%");
	ft_strcpy(tab->flg_list, "-0.*");
	tab->cnv_eval[0] = &ft_print_char;
	tab->cnv_eval[1] = &ft_print_str;
	tab->cnv_eval[2] = &ft_print_pointer;
	tab->cnv_eval[3] = &ft_print_int;
	tab->cnv_eval[4] = &ft_print_int;
	tab->cnv_eval[5] = &ft_print_unsigned_int;
	tab->cnv_eval[6] = &ft_print_hex_low;
	tab->cnv_eval[7] = &ft_print_hex_cap;
	tab->cnv_eval[8] = &ft_print_percent;
	tab->flg_eval[0] = &ft_flag_dash;
	tab->flg_eval[1] = &ft_flag_zero;
	tab->flg_eval[2] = &ft_flag_point;
	tab->flg_eval[3] = &ft_flag_star;
}

void	ft_init_tab(t_print *tab)
{
	ft_reset_tab(tab);
	tab->tl = 0;
	ft_config_tab(tab);
}
