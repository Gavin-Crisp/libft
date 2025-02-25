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

static t_chunk	*get_best_fit(t_chunk *chunks, size_t size)
{
	t_chunk	*out;
	size_t	diff;
	size_t	best_diff;

	out = 0;
	best_diff = SIZE_MAX;
	while (chunks)
	{
		if (chunks->is_free && size <= chunks->size)
		{
			diff = chunks->size - size;
			if (!diff)
				return (out);
			if (diff < best_diff)
			{
				best_diff = diff;
				out = chunks;
			}
		}
		chunks = chunks->next;
	}
	return (out);
}

static void	insert_chunk(t_chunk *chunks, t_chunk *new)
{
	new->next = chunks->next;
	new->prev = chunks;
	chunks->next = new;
	if (new->next)
		new->next->prev = new;
}

void	*ft_malloc(size_t size)
{
	t_chunk	*best_chunk;

	if (!size)
		return (0);
	best_chunk = get_best_fit(get_heap()->meta, size);
	if (!best_chunk)
		return (0);
	best_chunk->is_free = 0;
	insert_chunk(best_chunk, new_chunk(
		best_chunk + sizeof(t_chunk) + size,
		best_chunk->size - size - sizeof(t_chunk),
		1));
	best_chunk->size = size;
	return (0);
}
