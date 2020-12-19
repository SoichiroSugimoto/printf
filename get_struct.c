/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:30:21 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/18 22:02:06 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/Libft.h"

//文字列から数値を取得する (+桁数分インクリメントする)
int get_number(char *st)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (st[i] && st[i] >= '0' && st[i] <= '9')
	{
		if ((0 <= st[i] && st[i] <= 47) || (58 <= st[i] && st[i] <= 127))
			return (0);
		num = num * 10;
		num += (int)st[i] - '0';
		i++;
	}
	return (num);
}

static	int		get_digit(int n)
{
	int len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

//ft_printf側で%以下文字分をインクリメントする必要があるためf_list get_struct(char *st, int i)
//に変換する。またwhileはいらない。
f_list get_struct(const char *st, int i)
{
	f_list f = {-1, -1, -1, -1, 'c', -1, "string", 'c'};

	while (st[i])
	{
		if (st[i] == '%')
		{
			i++;
			if (st[i] == '0')
			{
				f.flag = 0;
				i++;
			}
			if (st[i] == '-')
			{
				f.flag = 1;
				i++;
			}
			if (st[i] == '0')
				i++;
			if (st[i] == '*')
			{
				f.f_flag = 1;
				i++;
			}
			if (st[i] && st[i] >= '0' && st[i] <= '9')
			{
				f.field = get_number(&st[i]);
				i += get_digit(f.field);
			}
			if (st[i] == '.')
			{
				f.precise = 0;
				i++;
				if (st[i] && st[i] >= '0' && st[i] <= '9')
				{
					f.precise = get_number(&st[i]);
					i += get_digit(f.precise);
				}
			}
			f.conversion = st[i];
		}
		i++;
	}
	return (f);
}


/*

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

/*
#include <stdio.h>
int main(void)
{
	f_list f;
	int i = 12345;
	int n = 0;

	char *string = "this is string";

	printf("%-*.5d\n", 3, i);
	char st[] = "%-*.5d";
	printf("%s\n", st);
	f = get_struct(st, n);



	f.str_value = string;
	f.int_value = i;


	printf("%d, %d, %d, %d, %c, %s, %d\n\n", f.flag, f.f_flag, f.field, f.precise, f.conversion, f.str_value, f.int_value);

	// f_list g;
	// int j = 12345;
	// printf("%-.5d\n", j);
	// char str[] = "%-.5d";
	// g = get_struct(str, n);
	// printf("%d, %d, %d, %d, %c\n", g.flag, g.f_flag, g.field, g.precise, g.conversion);
}

*/





