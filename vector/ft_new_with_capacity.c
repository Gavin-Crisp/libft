#include "libft.h"

t_vector	*ft_vecnew_with_capacity(size_t capacity, size_t elem_size)
{
	t_vector	*out;

	out = ft_vecnew(elem_size);
	ft_vecreserve(out, capacity);
	return (out);
}
