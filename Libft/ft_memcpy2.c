/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:35:30 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/31 11:01:18 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	*ft_memcpy2(void *dst, const void *src, int n)
{
	int				i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)dst;
	st2 = (unsigned char *)src;
	while (i <= n)
	{
		st1[i] = st2[i];
		i++;
	}
	return (dst);
}
