#include "allocator.h"

void	ft_free(void *ptr)
{
	t_chunk	*chunk;

	if (!ptr)
		return ;
	chunk = ptr - sizeof(t_chunk);
	if (!is_valid_chunk(chunk) || chunk->is_free)
		return ;
	free_chunk(&chunk);
}
