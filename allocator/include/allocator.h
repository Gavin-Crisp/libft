#ifndef ALLOCATOR_H
# define ALLOCATOR_H
# include "libft.h"

typedef struct s_heap
{
	t_list	*meta;
	unsigned char data[ALLOC_HEAP_CAPACITY];
}	t_heap;

typedef struct s_heap_chunk
{
	void	*start;
	size_t	size;
	int		is_free;
}	t_heap_chunk;

t_heap			*get_heap(void);

t_heap_chunk	*new_heap_chuck(void *start, size_t size, int is_free);

#endif
