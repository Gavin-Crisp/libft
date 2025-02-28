/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:24:14 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 12:24:30 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"

t_chunk	*get_heap(void)
{
	static unsigned char	raw_heap[ALLOC_HEAP_CAPACITY] = {0};

	if (((t_chunk *)raw_heap)->size == 0)
	{
		((t_chunk *)raw_heap)->prev = 0;
		((t_chunk *)raw_heap)->size = ALLOC_HEAP_CAPACITY - sizeof(t_chunk);
		((t_chunk *)raw_heap)->is_free = 1;
	}
	return ((t_chunk *)raw_heap);
}
