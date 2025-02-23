#include "allocator.h"

unsigned char	*get_heap(void)
{
	static unsigned char heap[ALLOC_HEAP_CAPACITY] = {0};

	return (heap);
}
