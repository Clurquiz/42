#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	(*del)(*alst->content);
	(*del)(*alst->content_size);
	(*del)(*alst->next);
	free(*alst);
	*alst = NULL;
}
