#include "libft.h"

void	*ft_vecpop(t_vector *vec, size_t index)
{
	void	*elem;
	void	*mem_loc;

	mem_loc = ft_vecindex(vec, index);
	ft_memcpy(elem, mem_loc, vec->_elem_size);
	ft_memmove(mem_loc, mem_loc + vec->_elem_size, vec->length - index - 1);
	vec->length--;
	return (elem);
}
