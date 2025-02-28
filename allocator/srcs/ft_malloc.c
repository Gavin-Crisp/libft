/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:26:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/25 12:15:28 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"

static t_chunk	*get_best_fit(t_chunk *chunk, size_t size)
{
	t_chunk	*out;
	size_t	diff;
	size_t	best_diff;

	out = 0;
	best_diff = -1;
	while (chunk)
	{
		if (chunk->is_free && size <= chunk->size)
		{
			diff = chunk->size - size;
			if (!diff)
				return (out);
			if (diff < best_diff)
			{
				best_diff = diff;
				out = chunk;
			}
		}
		chunk = chunk_next(chunk);
	}
	return (out);
}

void	*ft_malloc(size_t size)
{
	t_chunk	*new;
	t_chunk	*best_chunk;

	if (!size)
		return (0);
	best_chunk = get_best_fit(get_heap(), size);
	if (!best_chunk)
		return (0);
	best_chunk->is_free = 0;
	if (best_chunk->size - size >= sizeof(t_chunk))
	{
		new = new_chunk(best_chunk + size + sizeof(t_chunk), best_chunk, best_chunk->size - size - sizeof(t_chunk), 1);
		best_chunk->size = size;
		chunk_next(new)->prev = new;
	}
	return (chunk_start(best_chunk));
}
