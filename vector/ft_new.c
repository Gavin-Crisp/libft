#include "libft.h"

t_vector	*ft_vecnew(size_t elem_size)
{
	t_vector	*out;

	out = malloc(sizeof(t_vector));
	out->data = 0;
	out->length = 0;
	out->_capacity = 0;
	out->_elem_size = elem_size;
	return (out);
}
