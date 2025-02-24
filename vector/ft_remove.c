#include "libft.h"

void	ft_vecremove(t_vector *vec, size_t index, void (*clear)(void *))
{
	void	*mem_loc;

	mem_loc = ft_vecindex(vec, index);
	clear(mem_loc);
	ft_memmove(mem_loc, mem_loc + vec->_elem_size, vec->length - index - 1);
	vec->length--;
}
