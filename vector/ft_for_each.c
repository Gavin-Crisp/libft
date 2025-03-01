#include "libft.h"

void	ft_vecfor_each(t_vector *vec, void (*action)(void *, size_t))
{
	size_t	i;

	i = 0;
	while (i < vec->length)
	{
		action(ft_vecindex(vec, i), i);
		i++;
	}
}
