#include "allocator.h"

void	ft_free(void *ptr)
{
	t_chunk	*chunks;

	if (!ptr)
		return ;
	chunks = find_chunk(ptr);
	if (!chunks || chunks->is_free)
		return ;
	free_chunk(&chunks);
}
