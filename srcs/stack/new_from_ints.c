/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_from.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:23:59 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/23 15:20:53 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stacknew_from_ints(int *arr, size_t length)
{
	t_stack	*new;
	int		*tmp;

	new = malloc(sizeof(t_stack));
	new->size = length;
	new->data = 0;
	while (length-- != 0)
	{
		tmp = malloc(sizeof(int));
		*tmp = arr[length];
		ft_lstadd_front(&(new->data), ft_lstnew(tmp));
	}
	return (new);
}
