/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:44:14 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/29 18:44:29 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = (char*)malloc(size * count);
	if (p == NULL)
		return (0);
	ft_bzero(p, (count * size));
	return ((void *)p);
}
