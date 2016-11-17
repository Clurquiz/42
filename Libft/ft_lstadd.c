
#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new)
{
	t_list	tmp;

	if (*alst)
	{
		tmp = *alst->next;
		*alst->next = new;
		new->next = tmp;
	}
	else
		*alst = new;
}
