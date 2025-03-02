#include "libft.h"

void	*ft_vecpop(t_vector *vec)
{
	return (ft_vecremove(vec, vec->length - 1));
}
