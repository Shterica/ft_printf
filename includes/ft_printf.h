#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifdef __APPLE__
#  define OS 0
# endif

# ifdef __unix__
#  define OS 1
# endif

# ifndef __APPLE__
#  ifndef __unix__
#   define OS 2
#  endif
# endif

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
 *  sp:		' ' flag
 *  hash:	'#' flag
 *  plus:	'+' flag
 *  cnv_list:	string of supported conversions
 *  flg_list:	string of supported flags
 *  cnv_eval:	array of function pointers for conversion evaluation
 *  flg_eval:	array of function pointers for flags evaluation
 */
typedef struct s_print
{
	va_list		args;
	int			wdt;
	int			prc;
	int			zero;
	int			pnt;
	int			dash;
	int			tl;
	int			sign;
	int			sp;
	int			hash;
	int			plus;
	char		base[17];
	char		prefix[3];
	char		null[7];
	char		cnv_list[10];
	char		flg_list[8];
	void		(*cnv_eval[9])(struct s_print *);
	int			(*flg_eval[7])(struct s_print *, const char *, int);
}		t_print;

/* MAIN FUNC (ft_printf.c) */

int		ft_printf(const char *format, ...);

/* FT_PRINTF UTILS (ft_printf_utils.c) */

void	ft_reset_tab(t_print *tab);
void	ft_config_tab(t_print *tab);
void	ft_init_tab(t_print *tab);
int		ft_eval_format(t_print *tab, const char *format, int pos);

/* CONVERIONS FUNCS (ft_eval_conv.c, ft_eval_conv2.c) */

void	ft_print_char(t_print *tab);
void	ft_print_str(t_print *tab);
void	ft_print_pointer(t_print *tab);
void	ft_print_int(t_print *tab);
void	ft_print_unsigned_int(t_print *tab);
void	ft_print_hex_low(t_print *tab);
void	ft_print_hex_cap(t_print *tab);
void	ft_print_percent(t_print *tab);

/* FLAGS FUNCS (ft_eval_flag.c, ft_eval_flag2.c) */

int		ft_eval_width(t_print *tab, const char *format, int pos);
int		ft_flag_dash(t_print *tab, const char *format, int pos);
int		ft_flag_zero(t_print *tab, const char *format, int pos);
int		ft_flag_point(t_print *tab, const char *format, int pos);
int		ft_flag_star(t_print *tab, const char *format, int pos);
int		ft_flag_hash(t_print *tab, const char *format, int pos);
int		ft_flag_space(t_print *tab, const char *format, int pos);
int		ft_flag_plus(t_print *tab, const char *format, int pos);

/* CONV UTILS (ft_conv_utils.c) */

char	*ft_set_null(t_print *tab);
void	ft_print_empty(t_print *tab);
void	ft_print_nbr_left(t_print *tab);
void	ft_print_nbr_right(t_print *tab);

/* FLAG UTILS (ft_flag_utils.c) */

void	ft_update_tab(t_print *tab, int len);
void	ft_update_prefix(t_print *tab);

#endif
