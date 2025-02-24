#ifndef ALLOCATOR_H
# define ALLOCATOR_H
# include "libft.h"

typedef struct s_heap
{
	t_chunk			*meta;
	unsigned char	data[ALLOC_HEAP_CAPACITY];
}	t_heap;

typedef struct s_chunk t_chunk;
struct s_chunk
{
	t_chunk	*prev;
	size_t	size;
	int		is_free;
	t_chunk	*next;
};

t_heap	*get_heap(void);
t_chunk	*new_chunk(void *addr, size_t size, int is_free);
void	free_chunk(t_chunk **pchunks);
int		is_valid_chunk(t_chunk *chunk);

#endif
