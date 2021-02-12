/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:30:21 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:51:02 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static	int			get_number(const char *st)
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

static	t_list		get_precise_num(t_list f, const char **st)
{
	if (**st == '.')
	{
		f.precise = 0;
		*st += 1;
		if (**st == '*')
		{
			f.p_flag = 1;
			*st += 1;
		}
		if (**st && **st >= '0' && **st <= '9')
		{
			f.precise = get_number(*st);
			*st += sub_get_digit(*st);
		}
	}
	return (f);
}

t_list				get_struct(const char *st)
{
	t_list f;

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
	f = get_precise_num(f, &st);
	f.conversion = *st;
	return (f);
}
