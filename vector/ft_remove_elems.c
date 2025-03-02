#include "libft.h"

void *ft_vecremove_elems(t_vector *vec, size_t index, size_t num_elems)
{
	void	*elems;
	void	*mem_loc;

	if (index >= vec->length || num_elems > vec->length - index)
		return (0);
	elems = malloc(num_elems * vec->_elem_size);
	mem_loc = ft_vecindex(vec, index);
	ft_memcpy(elems, mem_loc, num_elems * vec->_elem_size);
	ft_memmove(mem_loc, mem_loc + num_elems * vec->_elem_size, (vec->length - index - num_elems) * vec->_elem_size);
	vec->length -= num_elems;
	return (elems);
}
