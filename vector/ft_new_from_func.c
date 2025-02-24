#include "libft.h"

t_vector	*ft_vecnew_from_func(size_t length, void *(*gen)(size_t), size_t elem_size)
{
	t_vector	*out;
	size_t		i;
	void		*tmp;

	out = malloc(sizeof(t_vector));
	out->length = length;
	out->_capacity = length;
	out->data = ft_malloc(out->_capacity);
	out->_elem_size = elem_size;
	i = 0;
	while (i < length)
	{
		tmp = gen(i);
		ft_memcpy(ft_vecindex(out, i++), tmp, elem_size);
		free(tmp);
	}
	return (out);
}
