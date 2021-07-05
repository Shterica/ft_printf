#ifndef FT_PRINTF
# define FT_PRINTF

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
 * Structure: s_print
 * ------------------
 *  Stores parameters of current conversion
 *
 *  args:	argument to print
 *  wdt:	width
 *  prc:	precision
 *  zero:	zero padding
 *  pnt:	'.' flag
 *  dash:	'-' flag
 *  tl:		total length (return value)
 *  sign:	bool for number's sign
 *  is_zero:	bool for numbers abs value
 *  perc:	'%' flag
 *  sp:		' ' flag
 *  cnv_list:	string of supported conversions
 *  flg_list:	string of supported flags
 *  cnv_eval:	array of function pointers for conversion evaluation
 *  flg_eval:	array of function pointers for flags evaluation
 */
typedef struct s_print
{
	va_list	args;
	int	wdt;
	int	prc;
	int	zero;
	int	pnt;
	int	dash;
	int	tl;
	int	sign;
	int	is_zero;
	int	perc;
	int	sp;
	char	cnv_list[10];
	char	flg_list[5];
	void	(*cnv_eval[9])(struct s_print *);
	int	(*flg_eval[4])(struct s_print *, const char *, int);
}		t_print;

/* MAIN FUNC (ft_printf.c) */

int	ft_printf(const char *format, ...);

/* FT_PRINTF UTILS (ft_printf_utils.c) */

void	ft_reset_tab(t_print *tab);
void	ft_config_tab(t_print *tab);
void	ft_init_tab(t_print *tab);
int	ft_eval_format(t_print *tab, const char *format, int pos);

/* CONVERIONS FUNCS (ft_eval_conv.c, ft_eval_conv2.c) */

void	ft_print_char(t_print *tab);
void	ft_print_str(t_print *tab);
void	ft_print_pointer(t_print *tab);
void	ft_print_int(t_print *tab);
void	ft_print_unsigned_int(t_print *tab);
void	ft_print_hex_low(t_print *tab);
void	ft_print_hex_cap(t_print *tab);
void	ft_print_percent(t_print *tab);

/* FLAGS FUNCS (ft_eval_flag.c) */

int	ft_eval_width(t_print *tab, const char *format, int pos);
int	ft_flag_dash(t_print *tab, const char *format, int pos);
int	ft_flag_zero(t_print *tab, const char *format, int pos);
int	ft_flag_point(t_print *tab, const char *format, int pos);
int	ft_flag_star(t_print *tab, const char *format, int pos);

#endif
