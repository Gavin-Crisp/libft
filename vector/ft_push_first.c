#include "libft.h"

int	ft_vecpush_first(t_vector *vec, void *elem)
{
	return (ft_vecinsert(vec, elem, 0));
}
