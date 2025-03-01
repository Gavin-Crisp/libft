#include "libft.h"

int	ft_vecpush_last(t_vector *vec, void *elem)
{
	return (ft_vecinsert(vec, elem, vec->length));
}
