/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 19:06:35 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/27 22:08:50 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(void *ptr, int *count)
{
	unsigned long	num;

	if (!ptr || ptr == 0)
		return (ft_putstr("(nil)", count));
	num = (unsigned long)ptr;
	*count += write(1, "0x", 2);
	ft_putnbr_hex(num, "0123456789abcdef", count);
}

void	ft_putnbr_hex(unsigned long n, char *cad, int *count)
{
	int	num;

	num = 0;
	if (n < 16)
		*count += write(1, &cad[n], 1);
	else
	{
		num = n % 16;
		ft_putnbr_hex(n / 16, cad, count);
		*count += write(1, &cad[num], 1);
	}
	return ;
}

void	ft_check(va_list *args, char c, int *count)
{
	if (c == '%')
		ft_putchar('%', count);
	else if (c == 'c')
		ft_putchar(va_arg(*args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(*args, char *), count);
	else if (c == 'p')
		ft_putptr(va_arg(*args, void *), count);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(*args, int), count);
	else if (c == 'x')
		ft_putnbr_hex(va_arg(*args, unsigned int), "0123456789abcdef", count);
	else if (c == 'X')
		ft_putnbr_hex(va_arg(*args, unsigned int), "0123456789ABCDEF", count);
	else if (c == 'u')
		ft_putnbr(va_arg(*args, unsigned int), count);
	return ;
}

int	ft_printf(char const *s, ...)
{
	va_list		args;
	int			i;
	int			count;

	i = 0;
	count = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
			return (-1);
		if (s[i] == '%')
		{
			i++;
			ft_check(&args, s[i], &count);
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
