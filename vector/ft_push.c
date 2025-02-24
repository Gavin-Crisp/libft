#include "libft.h"

void	ft_vecpush(t_vector *vec, void *elem)
{
	ft_vecinsert(vec, elem, vec->length - 1);
}
