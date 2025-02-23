#include "allocator.h"

t_heap	*get_heap(void)
{
	static t_heap	heap = {0};

	if (!heap.meta)
	{
		heap.meta = ft_lstnew(new_heap_chuck(
				heap.data,
				ALLOC_HEAP_CAPACITY,
				1));
	}
	return (&heap);
}
