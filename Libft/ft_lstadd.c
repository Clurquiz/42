
#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new)
{
	t_list	tmp;

	tmp = *alst->next;
	*alst->next = new;
	new->next = tmp;
}
