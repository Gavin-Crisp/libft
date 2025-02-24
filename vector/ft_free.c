#include "libft.h"

void	ft_vecfree(t_vector **pvec, void (*clear)(void *))
{
	size_t	i;

	i = 0;
	while (i < (*pvec)->length)
		clear(ft_vecindex(*pvec, i++));
	ft_free((*pvec)->data);
	free(*pvec);
	*pvec = 0;
}
