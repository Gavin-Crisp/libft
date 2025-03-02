#include "libft.h"

int	ft_vecpush(t_vector *vec, void *elem)
{
	return (ft_vecinsert(vec, elem, vec->length));
}
