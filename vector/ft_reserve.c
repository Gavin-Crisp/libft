#include "libft.h"

static size_t	next_highest_p2(size_t n)
{
	size_t	power;

	power = 1;
	while (power <= n)
		power *= 2;
	return (power);
}

void	ft_vecreserve(t_vector *vec, size_t num_elements)
{
	if (vec->length + num_elements <= vec->_capacity)
		return ;
	vec->_capacity = next_highest_p2(vec->_capacity + num_elements);
	vec->data = ft_realloc(vec->data, vec->_capacity * vec->_elem_size);
}
