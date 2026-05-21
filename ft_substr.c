/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:21:51 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/21 15:21:52 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cad;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s_len <= (size_t)start || len == 0)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	cad = malloc(sizeof(char) * (len + 1));
	if (!cad)
		return (NULL);
	while (i < len)
	{
		cad[i] = s[(size_t)start + i];
		i++;
	}
	cad[i] = '\0';
	return (cad);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s", ft_substr("lorem ipsum dolor sit amet", 0, 10));
	return (0);
}*/
