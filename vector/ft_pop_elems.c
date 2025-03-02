#include "libft.h"

void	*ft_vecpop_elems(t_vector *vec, size_t num_elems)
{
	return (ft_vecremove_elems(vec, vec->length - 1, num_elems));
}
