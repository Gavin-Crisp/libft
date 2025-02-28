#include "allocator.h"

t_chunk	*chunk_next(t_chunk *chunk)
{
	return (chunk + chunk->size + sizeof(chunk));
}

void	*chunk_start(t_chunk *chunk)
{
	if (chunk->size)
		return (chunk + sizeof(chunk));
	return (0);
}

t_chunk	*new_chunk(void *addr, t_chunk *prev, size_t size, int is_free)
{
	t_chunk	*out;

	out = addr;
	out->prev = prev;
	out->size = size;
	out->is_free = is_free;
	return (out);
}

int	chunk_is_valid(t_chunk *chunk)
{
	return (chunk_next(chunk->prev) == chunk);
}

void	merge_with_next(t_chunk *chunk)
{
	if (chunk->is_free && chunk_next(chunk)->is_free)
	{
		chunk->size += chunk_next(chunk)->size + 1;
		chunk_next(chunk)->prev = chunk;
	}
}
