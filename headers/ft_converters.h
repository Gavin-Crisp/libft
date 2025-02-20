/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:32:53 by gcrisp            #+#    #+#             */
/*   Updated: 2023/06/02 11:37:03 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTERS_H
# define CONVERTERS_H
# include <stdlib.h>

int		ft_atoi(const char *s);
long	ft_atol(const char *s);
double	ft_atod(const char *s);
char	*ft_itoa(int n);
char	*ft_itoa_base(int n, char *base);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_base(unsigned int n, char *base);
char	*ft_ultoa_base(unsigned long n, char *base);
#endif
