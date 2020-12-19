/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:15:00 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/19 18:20:53 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/Libft.h"

static	int		get_digit(int n)
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

static	int		get_digit_hex(int n)
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

int get_realm(f_list f)
{
	int size;

	if (f.conversion == 's')
	{
		size = ft_strlen(f.str_value);
		if (size > f.precise)
			size = f.precise;
		if (size < f.field)
			size = f.field;
	}
	if (f.conversion == 'c')
	{
		size = 1;
		if (size < f.field)
			size = f.field;
	}
	if (f.conversion == 'x')
	{
		size = get_digit_hex(f.int_value);
		if (size > f.precise)
			size = f.precise;
		if (size < f.field)
			size = f.field;
	}
	else
	{
		size = get_digit(f.int_value);
		if (size > f.precise)
			size = f.precise;
		if (size < f.field)
			size = f.field;
	}
	return (size);
}

//[[[value]length]size]
int get_length(f_list f)
{
	int size;

	if (f.conversion == 's')
	{
		size = ft_strlen(f.str_value);
		if (size > f.precise)
			size = f.precise;
	}
	if (f.conversion == 'c')
		size = 1;
	else
	{
		size = get_digit(f.int_value);
		if (size > f.precise)
			size = f.precise;
	}
	return (size);
}

char *arrange_value(f_list f)
{
	char *p;
	char *q;
	int size;
	int length;
	int i;

	i = 0;
	size = get_realm(f);
	if (!(p = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	length = get_length(f);
	if (!(q = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	if (f.conversion == 's')
	{
		if (f.flag != 1)
		{
			while (i != length)
			{
				p[i] = f.str_value[i];
				i++;
			}
			while (i != size)
			{
				p[i] = ' ';
				i++;
			}
		}
		if (f.flag == 1)
		{
			while (i != (size - length))
			{
				p[i] = ' ';
				i++;
			}
			while (i != size)
			{
				p[i] = f.str_value[i];
				i++;
			}
		}
	}
	if (f.conversion == 'c')
	{
		if (f.flag != 1)
		{
			p[i] = f.char_value;
			while (i != size)
			{
				p[i] = ' ';
				i++;
			}
		}
		if (f.flag == 1)
		{
			while (i != size - 1)
			{
				p[i] = ' ';
				i++;
			}
			p[i] = f.char_value;
		}
	}

	size = get_realm(f);
	if (!(p = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (f.conversion == 'x' || f.conversion == 'X')
		q = into_hex(f.int_value);
	else
		q = ft_itoa(f.int_value);
	if (f.conversion == 'd' || f.conversion == 'i' || f.conversion == 'u')
	{
		if (f.flag == 0 && f.precise == -1)
		{
			while (i <= size - length)
			{
				p[i] = '0';
				i++;
			}
			while (i <= length - get_digit(f.int_value))
			{
				p[i] = q[i];
				i++;
			}
		}
		if (f.flag == 1)
		{
			while (i <= size - length)
			{
				p[i] = ' ';
				i++;
			}
			while (i <= length - get_digit(f.int_value))
			{
				p[i] = q[i];
				i++;
			}
		}
		else
		{
			while (i <= length - get_digit(f.int_value))
			{
				p[i] = q[i];
				i++;
			}
			while (i <= size)
			{
				p[i] = q[i];
				i++;
			}
		}
	}
	return (p);
}


/*

[[[value]length]size]
length = get_length;
size = get_realm;

------> flag		: <int>		(-1)[1, 0, -1]
		f-flag		: <int>		(-1)[-1, 1]
		field		: <int>		(-1)[-1, 数値]
		precise		: <int>		(-1)[-1, 数値]
		conversion	: <char>	(c)[c, s, p, d, i, u, x, X, %]

typedef struct
{
	int flag;
	int f_flag;
	int field;
	int precise;
	char conversion;
	int	int_value;
	char *str_value;
	char char_value;
} f_list;

*/