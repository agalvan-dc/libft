
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n <= 9)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else if (n > 9)
	{
	c = n % 10 + '0';
	ft_putnbr_fd(n/10, fd);
	write(fd, &c, 1);
	}
	return ;
}
/*
int	main(void)
{
	ft_putnbr_fd(4343242, 1);
	return (0);
}*/
