#include "libft.h"

t_vector	*ft_vecmap(t_vector *vec, void *(*map)(void *, size_t))
{
	t_vector	*out;
	size_t		i;
	void		*new_elem;

	out = malloc(sizeof(t_vector));
	out->length = vec->length;
	out->_capacity = vec->_capacity;
	out->_elem_size = vec->_elem_size;
	out->data = ft_malloc(out->_capacity);
	i = 0;
	while (i < vec->length)
	{
		new_elem = map(ft_vecindex(vec, i), i);
		ft_memcpy(ft_vecindex(out, i++), new_elem, out->_elem_size);
		free(new_elem);
	}
	return (out);
}
