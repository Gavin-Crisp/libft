#include "libft.h"

int	ft_vecdelete(t_vector *vec, size_t index, void (*clear)(void *))
{
	void	*mem_loc;

	if (index >= vec->length)
		return (0);
	mem_loc = ft_vecindex(vec, index);
	if (clear)
		clear(mem_loc);
	ft_memmove(mem_loc, mem_loc + vec->_elem_size, (vec->length - index - 1) * vec->_elem_size);
	vec->length--;
	return (1);
}
