#include "libft.h"

static char	*ft_memalloc(int n)
{
	char *p;
	int count;

	count = 0;
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
	p = (char *)malloc(sizeof(char) * (count + 1));
	if (!p)
		return (NULL);
	return (p);
}

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_reverse(char *s)
{
	int i;
	int j;
	char temp;
	
	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

char	*ft_itoa(int n)
{
	int i;
	int sign;
	char *p;
	
	p = ft_memalloc(n);
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	p[i++] = n % 10 + '0';
	n /= 10;
	while (n > 0)
	{
		p[i++] = n % 10 + 48;
		n /= 10;
	}
	if (sign < 0)
		p[i++] = '-';
	p[i] = '\0';
	ft_reverse(p);
	return (p);
}
