/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:30:21 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/02 08:19:11 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../Libft/Libft.h"

static int				get_number(const char *st)
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

static int		get_digit(int n)
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

// static f_list			ft_init_flag(f_list f)
// {
// 	f.flag = -1;
// 	f.f_flag = -1;
// 	f.field = -1;
// 	f.precise = -1;
// 	f.p_flag = -1;
// 	f.conversion = 'c';
// 	f.int_value = -1;
// 	f.str_value = NULL;
// 	f.char_value = 'c';
// 	f.adr_value = -1;
// 	return (f);
// }

static f_list			ft_get_flag(const char *st, f_list f)
{
	if (*st == '0')
	{
		f.flag = 0;
		st++;
	}
	if (*st == '-')
	{
		f.flag = 1;
		st++;
	}
	if (*st == '0')
		st++;
	if (*st == '*')
	{
		f.f_flag = 1;
		st++;
	}
	return (f);
}

f_list			get_struct(const char *st)
{
	f_list f = {-1, -1, -1, -1, -1, 'c', -1, "", 'c', -1};

	printf("[%s]\n", f.str_value);
	st++;
	f = ft_get_flag(st, f);
	while (*st == '0' || *st == '-' || *st == '*')
		st++;
	if (*st && *st >= '0' && *st <= '9')
	{
		f.field = get_number(&*st);
		st += get_digit(f.field);
	}
	if (*st == '.')
	{
		f.precise = 0;
		st++;
		if (*st && *st >= '0' && *st <= '9')
		{
			f.precise = get_number(st);
			st += get_digit(f.precise);
		}
	}
	f.conversion = *st;
	return (f);
}
