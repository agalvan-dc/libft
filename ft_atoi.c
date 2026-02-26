
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sum;
	int	i;
	int	sign;
	int	cont;

	i = 0;
	sum = 0;
	sign = 1;
	cont = 0;
	while (str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		sign *= -1;
		cont++;
		i++;
	}
	if (cont > 1)
		return (0);
	while(str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	return (sum * sign);
}
