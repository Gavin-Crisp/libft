#include "allocator.h"

t_heap	*get_heap(void)
{
	static t_heap	heap = {0};

	if (!heap.meta)
	{
		heap.meta = new_chunk(
				heap.data,
				ALLOC_HEAP_CAPACITY,
				1);
	}
	return (&heap);
}

t_chunk	*find_chunk(void *ptr)
{
	t_chunk	*chunks;

	chunks = get_heap()->meta;
	while (chunks)
	{
		if (chunks->start == ptr)
			return (chunks);
		chunks = chunks->next;
	}
	return (0);
}

t_chunk	*new_chunk(void *start, size_t size, int is_free)
{
	t_chunk	*out;

	out = malloc(sizeof(t_chunk));
	out->start = start;
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
	free(chunk);
}

void	free_chunk(t_chunk **pchunks)
{
	remove_chunk(pchunks);
	if ((*pchunks)->is_free && (t_chunk *)(*pchunks)->prev->is_free)
	{
		(*pchunks)->prev->size += (*pchunks)->size;
		remove_chunk(pchunks);
	}
	*pchunks = 0;
}
