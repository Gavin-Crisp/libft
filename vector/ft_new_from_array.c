#include "libft.h"

t_vector	*ft_vecnew_from_array(void *elements, size_t length, size_t elem_size)
{
	t_vector	*out;

	out = ft_vecnew_with_capacity(length, elem_size);
	out->length = length;
	ft_memcpy(out->data, elements, length * elem_size);
	return (out);
}
