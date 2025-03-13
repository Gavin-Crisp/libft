/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:25:54 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/11 11:59:44 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_H
# define ALLOCATOR_H
# include "libft.h"

typedef struct s_chunk	t_chunk;
struct s_chunk
{
	t_chunk	*prev;
	size_t	size;
	int		is_free;
};

t_chunk	*get_heap(void);

void	*chunk_start(t_chunk *chunk);
t_chunk	*chunk_next(t_chunk *chunk);
t_chunk	*new_chunk(void *addr, t_chunk *prev, size_t size, int is_free);
int		chunk_is_valid(t_chunk *chunk);
void	merge_with_next(t_chunk *chunk);

#endif
