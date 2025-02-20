/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:53:42 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:17:01 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
#include "ft_linked_list.h"

typedef struct s_stack
{
	t_list	*data;
	size_t	size;
}	t_stack;

t_stack	*ft_stacknew(void);
t_stack	*ft_stacknew_from_ints(int *arr, size_t length);
t_stack	*ft_stacknew_from_list(t_list *lst);
void	ft_stackpush(t_stack *stack, int data);
int		ft_stackpop(t_stack *stack);
void	ft_stackrotate(t_stack *stack);
void	ft_stackrotate_rev(t_stack *stack);
void	ft_stackswap_top(t_stack *stack);
void	ft_stackclear(t_stack **stack);

#endif
