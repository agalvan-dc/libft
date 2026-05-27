/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:47:57 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/22 18:29:13 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size > 0 && count > (((size_t) - 1) / size))
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	if (size == 0 || count == 0)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}
