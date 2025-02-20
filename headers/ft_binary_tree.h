/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:13:55 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:16:00 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H
# include "stdlib.h"

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	size_t			key;
	void			*value;
}	t_btree;

t_btree	*ft_btreenew(size_t key, void *value);
t_btree	*ft_btreesearch(t_btree *root, size_t key);
void	ft_btreeinsert(t_btree **rootptr, t_btree *new);
void	ft_btreeinsert_balanced(t_btree **rootptr, t_btree *new);
void	ft_btreeclear(t_btree **rootptr, void (*fr)(void *));
void	ft_btreerotate_left(t_btree **rootptr);
void	ft_btreerotate_right(t_btree **rootptr);
void	ft_btreebalance(t_btree **rootptr);
size_t	ft_btreesize(t_btree *root);
size_t	ft_btreeheight(t_btree *root);
int		ft_btreeis_balanced(t_btree *root);
int		ft_btreebalance_factor(t_btree *root);
#endif
