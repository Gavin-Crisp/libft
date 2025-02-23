#include "libft.h"

t_list	*ft_lstfind_closest(t_list *head, void *ref, int (*cmp)(void *, void *))
{
	t_list	*closest;
	int		res;
	int		closest_res;

	if (!head)
		return (0);
	closest = head;
	closest_res = INT_MAX;
	while (head->next && closest_res != 0)
	{
		head = head->next;
		res = cmp(closest->data, head->data);
		if (res < 0)
			res = -res;
		if (res >= closest_res)
			continue ;
		closest_res = res;
		closest = head;
	}
	return (closest);
}
