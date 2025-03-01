#include "libft.h"

t_vector	*ft_vecnew_from_array(void *elements, size_t length, size_t elem_size)
{
	t_vector	*out;

	out = malloc(sizeof(t_vector));
	out->length = length;
	out->_elem_size = elem_size;
	out->_capacity = length * elem_size;
	out->data = ft_malloc(out->_capacity);
	ft_memcpy(out->data, elements, length * elem_size);
	return (out);
}
