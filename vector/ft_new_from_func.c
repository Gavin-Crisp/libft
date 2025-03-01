#include "libft.h"

t_vector	*ft_vecnew_from_func(size_t length, void *(*gen)(size_t), size_t elem_size)
{
	t_vector	*out;
	size_t		i;
	void		*new_elem;

	out = malloc(sizeof(t_vector));
	out->length = length;
	out->_elem_size = elem_size;
	out->_capacity = length * elem_size;
	out->data = ft_malloc(out->_capacity);
	i = 0;
	while (i < length)
	{
		new_elem = gen(i);
		ft_memcpy(ft_vecindex(out, i++), new_elem, elem_size);
		free(new_elem);
	}
	return (out);
}
