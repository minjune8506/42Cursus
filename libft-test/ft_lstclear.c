#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	while (*lst)
	{
		ft_lstdelone(*lst, (*lst) -> content);
		*lst = (*lst)->next;
	}
	free(lst);
}
