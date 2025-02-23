#include "libft.h"

t_dllist	*ft_dllstfind_closest(
				t_dllist *head,
				void *ref,
				int (*cmp)(void *, void *)
			)
{
	t_dllist	*closest;
	int			closest_res;
	int			res;

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
