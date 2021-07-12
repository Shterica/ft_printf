#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *nbr);
int		ft_numlen(unsigned long int nb, int base_len);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_hex(unsigned long int nb, const char *base);
int		ft_min(int a, int b);

#endif
