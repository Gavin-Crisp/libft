#include "allocator.h"

t_heap_chunk	*new_heap_chuck(void *start, size_t size, int is_free)
{
	t_heap_chunk	*out;

	out->start = start;
	out->size = size;
	out->is_free = is_free;
	return (out);
}
