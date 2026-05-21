/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:13:10 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/21 20:17:55 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (!lst || !new)
		return ;
	cur = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new;
	return ;
}
