
#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = lst;
	while (cur->next != NULL)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}
