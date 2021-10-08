#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_print
{
    va_list args;
    int wdt;
    int prc;
    int pnt;
    int tl;
}               t_print;

int     ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

int     ft_intlen(int nbr)
{
    long int    nb;

    nb = nbr;
    int count = 0;

    if (nb == 0)
        return (1);
    if (nb < 0)
    {
        count++;
        nb = -nb;
    }
    while (nb > 0)
    {
        nb /= 10;
        count++;
    }
    return (count);
}

int     ft_numlen(unsigned int nb, char *base)
{
    int baselen;
    int count;

    baselen = ft_strlen(base);
    count = 0;

    if (nb == 0)
        return (1);
    while (nb > 0)
    {
        nb /= baselen;
        count++;
    }
    return (count);
}
/*
void    putnbr_hex(unsigned long int nb, char *base)
{
    unsigned long int baselen;
    baselen = 16;
    
    if (nb < baselen)
    {
        write(1, &base[nb], 1);
    }
    else
    {
        putnbr_hex(nb / baselen, base);
        write(1, &base[nb % baselen], 1);
    }
}*/

void    putnbr_hex(unsigned long int nb, char *base)
{
    unsigned long int baselen;
    baselen = 16;
    
    if (nb >= baselen)
        putnbr_hex(nb / baselen, base);
    write(1, &base[nb % baselen], 1);
}

int ft_min(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

void    update_tab(t_print *tab, int len)
{
    if (len >= tab->wdt || tab->prc >= tab->wdt)
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

void    ft_putchar(char c)
{
    write(1 , &c, 1);
}

void    ft_putnbr(int nb, t_print *tab)
{
    long int nbr;

    nbr = nb;
    if (nb < 0)
    {
        write(1, "-", 1);
        nbr = -nbr;
    }
    while (tab->prc-- > 0)
        tab->tl += write(1, "0", 1);
    if (nbr < 10)
        ft_putchar(nbr + '0');
    else
    {
        ft_putnbr(nbr / 10, tab);
        ft_putchar(nbr % 10 + '0');
    }
}

int     ft_printf(const char *format, ...)
{
    int i = 0;
    int ret = 0;
    t_print *tab;

    tab = (t_print *)malloc(sizeof(t_print));
    if (!tab)
        return (-1);
    tab->prc = 0;
    tab->pnt = 0;
    tab->tl = 0;
    tab->wdt = 0;
    va_start(tab->args, format);
    while (format[i])
    {
        if (format[i] != '%')
        {
            ret += write(1, &format[i], 1);
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
                while (format[i] >= '0' && format[i] <= '9')
                {
                    tab->prc = tab->prc * 10 + (format[i] - '0');
                    i++;
                }
            }
            if (format[i] == 's')
            {
                char *s = va_arg(tab->args, char *);
                int len = 0;
                int k = 0;
                if (!s)
                    s = "(null)";
                len = ft_strlen(s);
                if (tab->pnt)
                {
                    len = ft_min(len, tab->prc);
                    tab->prc = 0;
                }
                update_tab(tab, len);
                while (tab->wdt-- > 0)
                    tab->tl += write(1, " ", 1);
                while (k < len && s[k])
                {
                    tab->tl += write(1, &s[k], 1);
                    k++;
                }
                tab->wdt = 0;
                tab->prc = 0;
                tab->pnt = 0;
                i++;
            }
            else if (format[i] == 'd')
            {
                int leni = 0;
                int sign = 0;
                int nb = va_arg(tab->args, int);
                if (nb == 0 && tab->prc == 0 && tab->pnt)
                {
                    while (tab->wdt-- > 0)
                        tab->tl += write(1, " ", 1);
                    tab->wdt = 0;
                    tab->prc = 0;
                    tab->pnt = 0;
                    i++;
                    continue;
                }
                if (nb < 0)
                {
                    tab->tl += 1;
                    sign = 1;
                }
                leni = ft_intlen(nb) - sign;
                update_tab(tab, leni);
                while (tab->wdt-- > 0)
                    tab->tl += write(1, " ", 1);
                ft_putnbr(nb, tab);
                tab->tl += leni;
                tab->wdt = 0;
                tab->prc = 0;
                tab->pnt = 0;
                i++;
            }
            else if (format[i] == 'x')
            {
                int lenx;
                unsigned long int xex = va_arg(tab->args, unsigned long int);
                if (xex == 0 && tab->prc == 0 && tab->pnt)
                {
                    while (tab->wdt-- > 0)
                        tab->tl += write(1, " ", 1);
                    tab->wdt = 0;
                    tab->prc = 0;
                    tab->pnt = 0;
                    i++;
                    continue ;
                }
                lenx = ft_numlen(xex, "0123456789abcdef");
                update_tab(tab, lenx);
                while (tab->wdt-- > 0)
                    tab->tl += write(1, " ", 1);
                while (tab->prc-- > 0)
                    tab->tl+= write(1, "0", 1);
                putnbr_hex(xex, "0123456789abcdef");
                tab->tl += lenx;
                tab->wdt = 0;
                tab->prc = 0;
                tab->pnt = 0;
                i++;
            }
            else
                return (-1);
        }
    }
    ret += tab->tl;
    va_end(tab->args);
    free(tab);
    return (ret);
}

/*
int main()
{
    printf("x4w %4x %4x %4x %4x %4x %4x %4x %4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
    ft_printf("x4w %4x %4x %4x %4x %4x %4x %4x %4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
    //ft_printf("%4d\n", (int)-2147483648);
    
    return (0);
}*/
