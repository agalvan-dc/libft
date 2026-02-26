
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_lst	*cur;
	
	cur = lst
	while (cur->next != NULL)
		cur = cur->next;

	return (cur);
}
