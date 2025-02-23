#include "allocator.h"

t_heap	*get_heap(void)
{
	static t_heap	heap = {0};

	if (!heap.meta)
	{
		heap.meta = ft_dllstnew(new_heap_chunk(
				heap.data,
				ALLOC_HEAP_CAPACITY,
				1));
	}
	return (&heap);
}
