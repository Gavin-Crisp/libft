#include "libft.h"

int ft_vec_push_elems(t_vector *vec, void *elems, size_t elem_count)
{
	return (ft_vecinsert_elems(vec, elems, elem_count, vec->length - 1));
}
