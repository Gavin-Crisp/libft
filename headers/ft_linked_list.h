/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:09:43 by gcrisp            #+#    #+#             */
/*   Updated: 2024/09/03 12:08:03 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H
# include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *data);
t_list	*ft_lstlast(t_list *head);
t_list	*ft_lstindex(t_list *head, size_t index);
t_list	*ft_lstfind(t_list *head, void *ref, int (*cmp)(void *, void *));
t_list	*ft_lstmap(t_list *head, void *(*f)(void *));
t_list	*ft_lstsplit(t_list **headptr, int (*pred)(void *),
			void (*f_free)(void *)); // Deletes split points
t_list	*ft_lstsplit_before(t_list **headptr, int (*pred)(void *));
t_list	*ft_lstpop(t_list **headptr, size_t index);
void	ft_lstadd_front(t_list **headptr, t_list *new);
void	ft_lstadd_back(t_list **headptr, t_list *new);
void	ft_lstremove(t_list **headptr, size_t index, void (*f_free)(void *));
void	ft_lstclear(t_list **headptr, void (*f_free)(void *));
void	ft_lstiter(t_list *head, void (*f)(void *));
size_t	ft_lstmin(t_list *head, int (*cmp)(void *, void *));
size_t	ft_lstmax(t_list *head, int (*cmp)(void *, void *));
size_t	ft_lstsize(t_list *head);
int		ft_lstis_sorted(t_list *head, int (*cmp)(void *, void *));

#endif
