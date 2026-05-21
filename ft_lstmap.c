/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:03:13 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/21 20:20:58 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*n_node;
	t_list	*aux;
	void	*a;

	n_node = NULL;
	while (lst)
	{
		a = f(lst->content);
		aux = ft_lstnew(a);
		if (!aux)
		{
			del(a);
			ft_lstclear(&n_node, del);
			return (n_node);
		}
		ft_lstadd_back(&n_node, aux);
		lst = lst->next;
	}
	return (n_node);
}
