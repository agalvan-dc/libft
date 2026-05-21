/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:05:40 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/18 19:05:47 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*c;
	const unsigned char	*p;
	size_t				i;

	i = 0;
	c = (unsigned char *)dst;
	p = (const unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		c[i] = p[i];
		i++;
	}
	return (dst);
}
