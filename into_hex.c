/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:31:03 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/18 22:01:42 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/Libft.h"
#include <stdio.h>

char refer_tab(int i)
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


static char		*itoc(int n, char *p, int i)
{
	if (n < 16)
	{
		p[0] = refer_tab(n);
		i--;
	}
	else
	{
		p[i] = refer_tab(n % 16);
		n = n / 16;
		i--;
		itoc(n, p, i);
	}
	return (p);
}

static	int		get_digit(int n)
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

char *into_hex(int n)
{
	char		*p;
	int			len;
	int			i;

	len = get_digit(n);
	i = len;
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	p[i] = '\0';
	i--;
	itoc(n, p, i);
	return (p);
}

// int main(void)
// {
// 	int i = 13453;
// 	printf("%s\n", into_hex(i));
// 	printf("%x\n", i);
// }

// int main(void)
// {
// 	int i = 12345;
// 	int n;
// 	int m;

// 	n = i /16;
// 	m = i %16;

// 	printf("商：%d　余り：%d\n", n, m);
// }