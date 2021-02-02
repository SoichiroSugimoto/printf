/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:58:14 by sosugimo          #+#    #+#             */
/*   Updated: 2021/01/04 19:02:58 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

static char		*itoa2(long int n, char *p, int i)
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

static	int		dgt_mes(long int n)
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

char			*ft_itoa(int n)
{
	char		*p;
	int			len;
	int			i;
	long int	l;

	len = dgt_mes(n);
	l = (long int)n;
	i = len;
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (l < 0)
	{
		p[0] = '-';
		l *= -1;
	}
	p[i] = '\0';
	i--;
	itoa2(l, p, i);
	return (p);
}
