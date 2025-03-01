#include "libft.h"

t_vector	*ft_vecnew_with_capacity(size_t capacity, size_t elem_size)
{
	t_vector	*out;

	out = malloc(sizeof(t_vector));
	out->length = 0;
	out->_elem_size = elem_size;
	out->_capacity = capacity * elem_size;
	out->data = ft_malloc(capacity);
	return (out);
}
