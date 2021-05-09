#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *list;
	
	if(!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->next = NULL;
	list->content = content;
	return (list);
}
