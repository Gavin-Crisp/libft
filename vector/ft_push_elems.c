#include "libft.h"

void	ft_vecpush_elems(t_vector *vec, void *elems, size_t num_elems)
{
	ft_vecinsert_elems(vec, elems, num_elems, vec->length - 1);
}
