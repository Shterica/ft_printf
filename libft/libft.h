#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

int	ft_isdigit(int c);
int	ft_atoi(const char *nbr);
int	ft_numlen(long int nb, int base_len);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strlen(char *s);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);

#endif
