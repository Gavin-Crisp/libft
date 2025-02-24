#include "allocator.h"

t_heap	*get_heap(void)
{
	static t_heap	heap = {0};

	if (!heap.meta)
	{
		heap.meta = new_chunk(
				heap.data,
				ALLOC_HEAP_CAPACITY - sizeof(t_chunk),
				1);
	}
	return (&heap);
}

int	is_valid_chunk(t_chunk *chunk)
{
	return (chunk->prev->next == chunk);
}

t_chunk	*new_chunk(void *addr, size_t size, int is_free)
{
	t_chunk	*out;

	out = addr;
	out->size = size;
	out->is_free = is_free;
	out->prev = 0;
	out->next = 0;
	return (out);
}

void	remove_chunk(t_chunk **pchunk)
{
	t_chunk	*chunk;

	chunk = *pchunk;
	if (chunk->prev)
	{
		chunk->prev->next = (*pchunk)->next;
		*pchunk = chunk->prev;
	}
	if (chunk->next)
	{
		chunk->next->prev = (*pchunk)->prev;
		*pchunk = chunk->next;
	}
	if (*pchunk == chunk)
		*pchunk = 0;
}

void	free_chunk(t_chunk **pchunks)
{
	(*pchunks)->is_free = 1;
	while (*pchunks && (*pchunks)->is_free && (*pchunks)->prev->is_free)
	{
		(*pchunks)->prev->size += (*pchunks)->size + sizeof(t_chunk);
		remove_chunk(pchunks);
	}
	*pchunks = 0;
}
