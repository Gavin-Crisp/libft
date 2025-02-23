#include "allocator.h"

t_chunk	*new_heap_chunk(void *start, size_t size, int is_free)
{
	t_chunk	*out;

	out->start = start;
	out->size = size;
	out->is_free = is_free;
	return (out);
}
