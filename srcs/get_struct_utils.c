/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:43:11 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/03 21:31:01 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../Libft/Libft.h"

f_list			ft_get_flag(const char *st, f_list f)
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

f_list			ft_init_flag(void)
{
	f_list f;

	f.flag = -1;
	f.f_flag = -1;
	f.field = -1;
	f.precise = -1;
	f.p_flag = -1;
	f.conversion = 'c';
	f.int_value = -1;
	f.str_value = NULL;
	f.char_value = 'c';
	f.adr_value = -1;
	return (f);
}

int				sub_get_digit(const char *st)
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
	return (i);
}
