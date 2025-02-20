/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:56:32 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:16:43 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H
# include <stdlib.h>

typedef struct s_dllist
{
	struct s_dllist	*prev;
	struct s_dllist	*next;
	void			*data;
}	t_dllist;

t_dllist	*ft_dllstnew(void *data);
t_dllist	*ft_dllstlast(t_dllist *head);
t_dllist	*ft_dllstfirst(t_dllist *elem);
t_dllist	*ft_dllstindex(t_dllist *head, size_t index);
t_dllist	*ft_dllstfind(t_dllist *head, void *ref,
				int (*cmp)(void *, void *));
void		ft_dllstadd_front(t_dllist **headptr, t_dllist *new);
void		ft_dllstadd_back(t_dllist **headptr, t_dllist *new);
void		ft_dllstinsert_before(t_dllist *elem, t_dllist *new);
void		ft_dllstinsert_after(t_dllist *elem, t_dllist *new);
void		ft_dllstremove(t_dllist **headptr, size_t index,
				void (*free)(void *));
void		ft_dllstremove_elem(t_dllist **elemptr, void (*fr)(void *));
void		ft_dllstclear(t_dllist **headptr, void (*free)(void *));
void		ft_dllstiter(t_dllist *head, void (*f)(void *));
size_t		ft_dllstsize(t_dllist *head);
int			ft_dllstis_sorted(t_dllist *head, int (*cmp)(void *, void *));
int			ft_dllstcmp(t_dllist *l1, t_dllist *l2, int (*cmp)(void *, void *));
int			ft_dllstmatch(t_dllist *find, t_dllist *in,
				int (*cmp)(void *, void *));

#endif
