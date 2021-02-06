/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:19:05 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/06 18:43:32 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/Libft.h"
#include "printf.h"
#include <stdio.h>

int		skip_str(const char *st, f_list f)
{
	int i;

	i = 1;
	while (st[i] && st[i] != f.conversion)
		i++;
	// if (f.conversion == '%')
	// {
	// 	while (st[i] != '%')
	// 		i++;
	// }
	//printf("%d\n", i + 1);
	return (i + 1);
}

int				compare_num(int i, int j, int order)
{
	int res;

	res = i;
	if (order == 1) ///大きい方
	{
		if (j > i)
			res = j;
	}
	else
	{
		if (j < i)
			res = j;
	}
	return (res);
}

int 			get_final_output(f_list f)
{
	int cnt;

	cnt = 1;
	if (f.conversion == 'c')
		cnt = compare_num(cnt, f.field, 1);
	else if (f.conversion == 's')
	{
		cnt = ft_strlen(f.str_value);
		cnt = compare_num(cnt, f.precise, 0);
		cnt = compare_num(cnt, f.field, 1);
	}
	else if (f.conversion == 'p')
		cnt = compare_num(14, f.field, 1);
	else if (f.conversion == 'd' || f.conversion == 'i' || f.conversion == 'u')
	{
		cnt = ft_strlen(ft_itoa(f.int_value));
		cnt = compare_num(cnt, f.precise, 1);	///////////大きい方
		cnt = compare_num(cnt, f.field, 1);	///////////
	}
	else
	{
		cnt = ft_strlen(into_hex(f.int_value, 1));
		cnt = compare_num(cnt, f.precise, 1);	//////////
		cnt = compare_num(cnt, f.field, 1);	//////////
	}
	return (cnt);
}

int				ft_printf(const char *st, ...)
{
	f_list	f;
	va_list	ap;
	int i;

	va_start(ap, st);
	i = 0;
	// if (!string)
	// 	return (FAILED);
	while (*st)
	{
		while (*st && *st == '%')
		{
			f = get_struct(st);
			if (f.f_flag == 1)
				f.field = va_arg(ap, int);
			if (f.p_flag == 1)
				f.precise = va_arg(ap, int);
			if (f.conversion == 'c')
				f.char_value = va_arg(ap, int);
			else if (f.conversion == 's')
				f.str_value = va_arg(ap, char*);
			else if (f.conversion == 'p')
				f.adr_value = (uintptr_t)va_arg(ap, char *);
			else
				f.int_value = va_arg(ap, int);
			central_arrange(f);
			st += skip_str(st, f);
			i += get_final_output(f);
		}
		write(1, st, 1);
		if (*st)
		{
			st++;
			i++;
		}
		//st += (*st ? 1 : 0);
	}
	va_end(ap);
	return (i);
}
