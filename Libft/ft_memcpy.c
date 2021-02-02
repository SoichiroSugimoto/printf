/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:59:40 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/27 03:16:41 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)dst;
	st2 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (i != n - 1)
	{
		st1[i] = st2[i];
		i++;
	}
	st1[i] = '\0';
	return (dst);
}
