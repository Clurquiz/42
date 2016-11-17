
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;

	current = *alst;
	while (current)
	{
		(*del)(current->content);
		(*del)(current->content_size);
		(*del)(current->next);
		free(current);
		current = current->next;
	}
		*alst = NULL;
}
