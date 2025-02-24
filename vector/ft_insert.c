#include "libft.h"

void	ft_vecinsert(t_vector *vec, void *elem, size_t num_elems, size_t index)
{
	ft_vecinsert_elems(vec, elem, 1, index);
}
