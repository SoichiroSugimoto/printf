/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:31:03 by sosugimo          #+#    #+#             */
/*   Updated: 2021/01/25 07:45:49 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../Libft/Libft.h"

char	refer_tab(long long i)
{
	if (i == 10)
		return ('a');
	if (i == 11)
		return ('b');
	if (i == 12)
		return ('c');
	if (i == 13)
		return ('d');
	if (i == 14)
		return ('e');
	if (i == 15)
		return ('f');
	else
		return ('0' + i);
}

char	refer_tabx(long long i)
{
	if (i == 10)
		return ('A');
	if (i == 11)
		return ('B');
	if (i == 12)
		return ('C');
	if (i == 13)
		return ('D');
	if (i == 14)
		return ('E');
	if (i == 15)
		return ('F');
	else
		return ('0' + i);
}

char		*itocx(long long n, char *p, int i, int prm)
{
	if (n < 16)
	{
		if (prm == 0)
			p[0] = refer_tab(n);
		else
			p[0] = refer_tabx(n);
		i--;
	}
	else
	{
		if (prm == 0)
			p[i] = refer_tab(n % 16);
		else
			p[i] = refer_tabx(n % 16);
		n = n / 16;
		i--;
		itocx(n, p, i, prm);
	}
	return (p);
}

int		get_digitx(long long n)
{
	int len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*into_hex(long long n, int prm)
{
	char		*p;
	int			len;
	int			i;

	len = get_digitx(n);
	i = len;
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	p[i] = '\0';
	i--;
	itocx(n, p, i, prm);
	return (p);
}
