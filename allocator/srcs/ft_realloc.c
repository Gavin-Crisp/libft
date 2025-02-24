#include "allocator.h"

static void	*contract_alloc(t_chunk *chunks, size_t new_size)
{
	t_chunk	*new;

	new = new_chunk(chunks + new_size, chunks->size - new_size, 1);
	new->next = chunks->next;
	chunks->next = new;
	new->prev = chunks;
	if (!new->next)
		return (chunks + sizeof(t_chunk));
	new->next->prev = new;
	return (chunks + sizeof(t_chunk));
}

static void	*expand_alloc(t_chunk *chunks, size_t new_size)
{
	t_chunk	*old;
	t_chunk	*new;
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
	chunks = ptr - sizeof(t_chunk);
	if (!is_valid_chunk(chunks) || chunks->is_free)
		return (ptr);
	if (new_size == chunks->size)
		return (ptr);
	if (new_size < chunks->size)
		return (contract_alloc(ptr, new_size));
	if (chunks->size + chunks->next->size <= new_size && chunks->next->is_free)
		return (expand_alloc(chunks, new_size));
	return (move_alloc(chunks, new_size));
}
