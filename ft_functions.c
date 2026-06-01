/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 19:03:58 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/27 22:04:42 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
	return ;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		*count += write(1, &str[i], 1);
		i++;
	}
	return ;
}

void	ft_putnbr(long int n, int *count)
{
	char	c;

	if (n < 0)
	{
		*count += write(1, "-", 1);
		ft_putnbr(-n, count);
	}
	else
	{
		if (n <= 9)
		{
			c = n + '0';
			*count += write(1, &c, 1);
		}
		else
		{
			c = n % 10 + '0';
			ft_putnbr(n / 10, count);
			*count += write(1, &c, 1);
		}
	}
	return ;
}
