#include "allocator.h"

void	ft_free(void *ptr)
{
	t_heap		*heap;
	t_dllist	*chunks;

	if (!ptr)
		return ;
	heap = get_heap();
	chunks = find_chunk(ptr);
	if (!chunks || ((t_chunk *)chunks->data)->is_free)
		return ;
	ft_dllstremove_elem(&chunks, free);
	if (((t_chunk *)chunks->data)->is_free && ((t_chunk *)chunks->prev->data)->is_free)
	{
		((t_chunk *)chunks->prev->data)->size += ((t_chunk *)chunks->data)->size;
		ft_dllstremove_elem(&chunks, free);
	}
}
