/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_from_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:21:00 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/23 15:22:33 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stacknew_from_list(t_list *lst)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->data = lst;
	new->size = ft_lstsize(lst);
	return (new);
}
