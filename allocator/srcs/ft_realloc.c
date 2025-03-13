/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:25:09 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:32:10 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"

static void	*contract_alloc(t_chunk *chunk, size_t new_size)
{
	t_chunk	*new;

	if (chunk->size - new_size < sizeof(t_chunk))
		return (chunk_start(chunk));
	new = new_chunk(chunk + new_size + sizeof(t_chunk), chunk,
			chunk->size - new_size - sizeof(t_chunk), 1);
	chunk->size = new_size;
	chunk_next(new)->prev = new;
	merge_with_next(new);
	return (chunk_start(chunk));
}

static void	*expand_alloc(t_chunk *chunk, size_t new_size)
{
	t_chunk	*new;
	size_t	comb_size;

	comb_size = chunk->size + chunk_next(chunk)->size;
	chunk->size = new_size;
	if (comb_size + sizeof(t_chunk) == new_size)
	{
		chunk_next(chunk)->prev = chunk;
		return (chunk_start(chunk));
	}
	new = new_chunk(chunk_next(chunk), chunk, comb_size - new_size, 1);
	chunk_next(new)->prev = new;
	return (chunk_start(chunk));
}

static void	*move_alloc(t_chunk *chunk, size_t new_size)
{
	void	*out;

	out = ft_malloc(new_size);
	ft_memcpy(out, chunk_start(chunk), chunk->size);
	chunk->is_free = 1;
	if (chunk->prev->is_free)
	{
		chunk = chunk->prev;
		merge_with_next(chunk);
	}
	merge_with_next(chunk);
	return (out);
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	t_chunk	*chunk;

	if (!ptr)
		return (ft_malloc(new_size));
	if (!new_size)
	{
		ft_free(ptr);
		return (0);
	}
	chunk = ptr - sizeof(t_chunk);
	if (chunk->is_free || !chunk_is_valid(chunk))
		return (ft_malloc(new_size));
	if (new_size == chunk->size)
		return (ptr);
	if (new_size < chunk->size)
		return (contract_alloc(ptr, new_size));
	if (chunk_next(chunk)->is_free
		&& chunk->size + chunk_next(chunk)->size + sizeof(t_chunk) >= new_size)
		return (expand_alloc(chunk, new_size));
	return (move_alloc(chunk, new_size));
}
