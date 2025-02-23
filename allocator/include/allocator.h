#ifndef ALLOCATOR_H
# define ALLOCATOR_H
# include "libft.h"

typedef struct s_heap
{
	t_dllist		*meta;
	unsigned char	data[ALLOC_HEAP_CAPACITY];
}	t_heap;

typedef struct s_chunk
{
	const void	*start;
	size_t		size;
	int			is_free;
}	t_chunk;

t_heap		*get_heap(void);
t_chunk		*new_heap_chunk(void *start, size_t size, int is_free);

#endif
