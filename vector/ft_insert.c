#include "libft.h"

static void	expand_vec(t_vector *vec)
{
	if (vec->_capacity == 0)
		vec->_capacity = 1;
	else
		vec->_capacity *= 2;
	vec->data = ft_realloc(vec->data, vec->_capacity);
}

int	ft_vecinsert(t_vector *vec, void *elem, size_t index)
{
	void	*mem_loc;

	if (index > vec->length)
		return (0);
	if (vec->_capacity < (vec->length + 1) * vec->_elem_size)
		expand_vec(vec);
	mem_loc = ft_vecindex(vec, index);
	ft_memmove(mem_loc + vec->_elem_size, mem_loc, vec->_elem_size * (vec->length - index));
	ft_memcpy(mem_loc, elem, vec->_elem_size);
	free(elem);
	vec->length++;
	return (1);
}
