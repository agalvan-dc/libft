
#include "libft.h"
//#include <stdio.h>
static char		*ft_putnbr(char *cad, int n, int dig)
{
	if (n < 0)
	{
		cad[0] = '-';
		n = -n;
	}
	cad[dig] = '\0';
	dig--;
	while (n > 0)
	{
		cad[dig] = n % 10 + '0';
		n /= 10;
		dig--;
	}
	return (cad);
}

char	*ft_itoa(int n)
{
	char	*cad;
	int		num;
	int		i;

	num = n;
	i = 0;
	if (n == 0)
		return ("0\0");
	if (n == -2147483648)
		return ("-2147483648\0");
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	cad = malloc(sizeof(char) * (i + 1));
	if (cad == NULL)
		return (NULL);

	cad = ft_putnbr(cad, n, i);
	return (cad);
}
/*
int		main(void)
{
	printf("%s", ft_itoa(0));
	return (0);
}*/
