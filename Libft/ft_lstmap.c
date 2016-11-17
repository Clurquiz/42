
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list (*f)(t_list *elem))
{
	t_list	*tmp;
	t_lisr	*start;

	tmp = lstnew(lst->content, lst->content_size);
	start = tmp;
	lst = lst->next;
	tmp = tmp->next;
	while (lst)
	{
		tmp = (*f)(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (start);
}
