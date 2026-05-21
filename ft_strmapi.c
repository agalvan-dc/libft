/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:42:23 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/21 14:42:54 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cad;
	size_t	i;

	i = ft_strlen(s);
	cad = malloc(sizeof(char) * (i + 1));
	if (cad == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cad[i] = f(i, s[i]);
		i++;
	}
	cad[i] = '\0';
	return (cad);
}
