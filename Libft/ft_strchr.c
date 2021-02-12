/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:09:30 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:49:45 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*st;
	int		len;

	i = 0;
	len = ft_strlen(s);
	st = (char *)s;
	while (i < len)
	{
		if (st[i] == c)
			return (&st[i]);
		i++;
	}
	return (0);
}
