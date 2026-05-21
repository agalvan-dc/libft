/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:21:34 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/18 19:22:54 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)s;
	c = (char)c;
	while (p[i] && p[i] != c)
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	if (p[i] == c)
		return (&p[i]);
	return (NULL);
}
