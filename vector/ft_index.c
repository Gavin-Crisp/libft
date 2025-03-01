#include "libft.h"

void	*ft_vecindex(t_vector *vec, size_t index)
{
	return (vec->data + index * vec->_elem_size);
}
