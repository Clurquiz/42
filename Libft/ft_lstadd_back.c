
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst)
	{
		while (*alist->next)
		*alist = *alist->next;
		*alist->next = new;
	}
	else
		*alst = new;
}
