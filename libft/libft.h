#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

int	ft_isdigit(int c);
int	ft_atoi(const char *nbr);
int	ft_numlen(int nb);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strlen(char *s);
char	*ft_itoa(int n);

#endif
