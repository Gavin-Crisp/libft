#include "allocator.h"

static int	size_diff(void *vchunk, void *vsize)
{
	size_t			*psize;
	t_heap_chunk	*chunk;

	psize = vsize;
	chunk = vchunk;
	if (*psize < chunk->size)
		return (chunk->size - *psize);
	return (*psize - chunk->size);
}

void	*ft_malloc(size_t size)
{
	t_heap		*heap;
	t_dllist	*best_chunk;

	if (!size)
		return (0);
	heap = get_heap();
	best_chunk = ft_dllstfind_closest(heap->meta, &size, size_diff);
	((t_heap_chunk *)(best_chunk->data))->is_free = 0;
	ft_dllstadd_front(&best_chunk->next, ft_lstnew(new_heap_chuck(
		(size_t)((t_heap_chunk *)(best_chunk->data))->start + size,
		((t_heap_chunk *)(best_chunk->data))->size - size,
		1)));
	((t_heap_chunk *)(best_chunk->data))->size = size;
	return (0);
}
