/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:30:21 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/03 18:29:14 by sosugimo         ###   ########.fr       */
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

// static int		get_digit(int n)
// {
// 	int len;

// 	len = 1;
// 	while (n >= 10)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

f_list			get_struct(const char *st)
{
	f_list f;
	f = ft_init_flag();

	st++;
	f = ft_get_flag(st, f);
	while (*st == '0' || *st == '-' || *st == '*')
		st++;
	if (*st && *st >= '0' && *st <= '9')
	{
		f.field = get_number(&*st);
		st += sub_get_digit(st);
	}
	if (*st == '.')
	{
		f.precise = 0;
		st++;
		if (*st && *st >= '0' && *st <= '9')
		{
			f.precise = get_number(st);
			st += sub_get_digit(st);
		}
	}
	f.conversion = *st;
	// printf("f.precise ------> <%d>\n", f.precise);
	// printf("f.conversion ------> <%c>\n", f.conversion);
	return (f);
}
