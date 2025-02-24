#include "libft.h"

t_vector	*ft_vecnew(size_t capacity, size_t elem_size)
{
	t_vector	*out;

	out = malloc(sizeof(t_vector));
	out->_capacity = capacity;
	out->_elem_size = elem_size;
	out->length = 0;
	out->data = ft_malloc(capacity);
	return (out);
}
