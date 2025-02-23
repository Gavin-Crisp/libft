#include "allocator.h"

void	free_chunk(t_dllist **pchunks)
{
	ft_dllstremove_elem(pchunks, free);
	if (((t_chunk *)(*pchunks)->data)->is_free && ((t_chunk *)(*pchunks)->prev->data)->is_free)
	{
		((t_chunk *)(*pchunks)->prev->data)->size += ((t_chunk *)(*pchunks)->data)->size;
		ft_dllstremove_elem(pchunks, free);
	}
	*pchunks = 0;
}

void	ft_free(void *ptr)
{
	t_dllist	*chunks;

	if (!ptr)
		return ;
	chunks = find_chunk(ptr);
	if (!chunks || ((t_chunk *)chunks->data)->is_free)
		return ;
	free_chunk(&chunks);
}
