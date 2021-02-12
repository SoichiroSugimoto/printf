/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:58:14 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:48:02 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*itoa2(long long n, char *p, int i)
{
	if (n < 10)
	{
		p[i] = '0' + n;
		i--;
	}
	else
	{
		p[i] = '0' + n % 10;
		n = n / 10;
		i--;
		itoa2(n, p, i);
	}
	return (p);
}

static	int		dgt_mes(long long n)
{
	int len;

	len = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char			*ft_itoa(long long n)
{
	char		*p;
	int			len;
	int			i;

	len = dgt_mes(n);
	i = len;
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	p[i] = '\0';
	i--;
	itoa2(n, p, i);
	return (p);
}
