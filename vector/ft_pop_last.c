#include "libft.h"

void	*ft_vecpop_last(t_vector *vec)
{
	return (ft_vecpop(vec, vec->length - 1));
}
