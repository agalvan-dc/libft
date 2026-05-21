/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:11:47 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/20 19:18:15 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cad;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	cad = malloc(sizeof(char) * (i + j + 1));
	if (!cad)
		return (NULL);
	while (k < i)
	{
		cad[k] = s1[k];
		k++;
	}
	while (k < i + j)
	{
		cad[k] = s2[k - i];
		k++;
	}
	cad[k] = '\0';
	return (cad);
}
/*
int	main(void)
{
	printf("%s", ft_strjoin("Hola", "Como estas"));
	
	return (0);
}*/
