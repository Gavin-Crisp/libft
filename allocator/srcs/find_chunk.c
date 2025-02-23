#include "allocator.h"

int	cmp_ptrs(void *vchunk, void *ptr)
{
	return (((t_chunk *)vchunk)->start != ptr);
}

t_dllist	*find_chunk(void *ptr)
{
	t_heap	*heap;

	heap = get_heap();
	return (ft_dllstfind(heap->meta, ptr, cmp_ptrs));
}
