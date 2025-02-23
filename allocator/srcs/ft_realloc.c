#include "allocator.h"

static void	*contract_alloc(t_chunk *chunks, size_t new_size)
{
	size_t	difference;

	difference = chunks->size - new_size;
	chunks->size = new_size;
	chunks->next->size += difference;
	chunks->next->start = (size_t)chunks->next->start - difference;
	return (chunks->start);
}

static void	*expand_alloc(t_chunk *chunks, size_t new_size)
{
	size_t	difference;

	difference = new_size - chunks->size;
	chunks->size = new_size;
	chunks->next->size -= difference;
	chunks->next->start = (size_t)chunks->next->start + difference;
	return (chunks->start);
}

static void	*move_alloc(t_chunk *chunks, size_t new_size)
{
	void	*out;

	out = ft_malloc(new_size);
	ft_memcpy(out, chunks->start, chunks->size);
	free_chunk(&chunks);
	return (out);
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	t_chunk	*chunks;

	if (!ptr)
		return (ft_malloc(new_size));
	if (!new_size)
	{
		ft_free(ptr);
		return (0);
	}
	chunks = find_chunk(ptr);
	if (!chunks || chunks->is_free)
		return (ptr);
	if (new_size == chunks->size)
		return (ptr);
	if (new_size < chunks->size)
		return (contract_alloc(ptr, new_size));
	if (chunks->size + chunks->next->size <= new_size)
		return (expand_alloc(chunks, new_size));
	return (move_alloc(chunks, new_size));
}
