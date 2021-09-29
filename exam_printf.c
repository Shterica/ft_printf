#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_print
{
	va_list args;
	int		wdt;
	int		prc;
	int		tl;
	int		pnt;
	int		sign;
	char	base[17];
}			t_print;

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_intlen(int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nb;
	char		*p;

	nb = n;
	i = ft_intlen(n);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	p[i--] = '\0';
	if (nb == 0)
		p[0] = 48;
	if (nb < 0)
	{
		p[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		p[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (p);
}

void	ft_putnbr_hex(unsigned long int nb, const char *base)
{
	unsigned long int	base_len;

	base_len = 16;
	if (nb < base_len)
		write(1, &base[nb], 1);
	else
	{
		ft_putnbr_hex(nb / base_len, base);
		write(1, &base[nb % base_len], 1);
	}
}

int	ft_numlen(unsigned long int nb, int base_len)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / base_len;
		i++;
	}
	return (i);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_update_tab(t_print *tab, int len)
{
	if (tab->wdt <= tab->prc || tab->wdt <= len)
		tab->wdt = 0;
	else if (tab->prc > len)
		tab->wdt -= tab->prc;
	else
		tab->wdt -= len;
	if (tab->prc <= len)
		tab->prc = 0;
	else
		tab->prc -= len;
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_printf(const char *format, ...)
{
	int i;
	int ret;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab->prc = 0;
	tab->wdt = 0;
	tab->tl = 0;
	tab->pnt = 0;
	tab->sign = 0;
	va_start(tab->args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ret += write(1, &format[i], 1);
			//printf("%c\n", format[i]);
			i++;
		}
		else if (format[i] == '%')
		{
			i++;
			while (format[i] >= '0' && format[i] <= '9')
			{
				tab->wdt = tab->wdt * 10 + (format[i] - '0');
				i++;
			}
			if (format[i] == '.')
			{
				i++;
				tab->pnt = 1;
				while(format[i] >= '0' && format[i] <= '9')
				{
					tab->prc = tab->prc * 10 + (format[i] - '0');
					i++;
				}

			}
			if (format[i] == 's')
			{
				int len = 0;
				int k = 0;
				char *str = va_arg(tab->args, char *);
				if (!str)
					str = "(null)";
				len = ft_strlen(str);
				if (tab->pnt)
				{
					len = ft_min(len, tab->prc);
					tab->prc = 0;
				}
				ft_update_tab(tab, len);
				while (tab->wdt-- > 0)
					tab->tl += write(1, " ", 1);
				while (k < len && str[k])
				{
					tab->tl += write(1, &str[k], 1);
					k++;
				}
				tab->prc = 0;
				tab->wdt = 0;
				tab->pnt = 0;
				tab->sign = 0;
				i++;
			}
			else if (format[i] == 'd')
			{
				int leni = 0;
				int j = 0;
				int nb = va_arg(tab->args, int);
				if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
				{
					tab->tl += write(1, "-", 1);
					while (tab->wdt-- > 0)
						tab->tl += write(1, " ", 1);
					break;
				}
				if (nb < 0)
					tab->sign = 1;
				char *nbr = ft_itoa(nb);
				if (!nbr)
					break ;
				leni = ft_strlen(nbr) - tab->sign;
				ft_update_tab(tab, leni);
				while (tab->wdt-- > 0)
					tab->tl += write(1, " ", 1);
				while (tab->prc-- > 0)
					tab->tl += write(1, "0", 1);
				j = tab->sign;
				while (nbr[j])
				{
					tab->tl += write(1, &nbr[j], 1);
					j++;
				}
				free(nbr);
				tab->prc = 0;
				tab->wdt = 0;
				tab->pnt = 0;
				tab->sign = 0;
				i++;
			}
			else if (format[i] == 'x')
			{
				unsigned int xex;
				int lenx;
				xex = va_arg(tab->args, unsigned int);
				ft_strcpy(tab->base, "0123456789abcdef");
				if (xex == 0 && tab->prc == 0 && tab->pnt == 1)
				{
					while (tab->wdt-- > 0)
						tab->tl += write(1, " ", 1);
					break ;
				}
				lenx = ft_numlen(xex, 16);
				ft_update_tab(tab, lenx);
				while (tab->wdt-- > 0)
					tab->tl += write(1, " ", 1);
				while (tab->prc-- > 0)
					tab->tl += write(1, "0", 1);
				ft_putnbr_hex(xex, tab->base);
				tab->tl += lenx;
				tab->prc = 0;
				tab->wdt = 0;
				tab->pnt = 0;
				tab->sign = 0;
				i++;
			}
			else
				return (-1);
		}
		//i++;

	}
	ret += tab->tl;
	va_end(tab->args);
	free(tab);
	return (ret);
}

int	main(int ac, char **av)
{
	int c;
	printf("%10.2s\n", "toto");
	ft_printf("%10.2s\n", "toto");
	printf("Magic %s is %5d\n", "number", 42);
	ft_printf("Magic %s is %5d\n", "number", 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
	c = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("c: %d\n", c);
	return (0);
}