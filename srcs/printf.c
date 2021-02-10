/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:19:05 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/10 19:47:35 by sosugimo         ###   ########.fr       */
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

	return (i + 1);
}

int				ft_printf(const char *st, ...)
{
	f_list	f;
	va_list	ap;
	// int i;

	va_start(ap, st);
	count = 0;
	// i = 0;
	// if (!string)
	// 	return (FAILED);
	while (*st)
	{
		if (*st == '%')
		{
			f = get_struct(st);
			if (f.f_flag == 1)
				f.field = va_arg(ap, int);
			if (f.field < 0 && f.field != -1)
			{
				f.flag = 1;
				f.field *= -1;
			}
			if (f.p_flag == 1)
				f.precise = va_arg(ap, int);
			if (f.p_flag == 1 && f.precise < 0)
				f.precise = -1;
			if (f.conversion == 'c')
				f.char_value = va_arg(ap, int);
			else if (f.conversion == 's')
				f.str_value = va_arg(ap, char*);
			else if (f.conversion == 'p')
				f.adr_value = (uintptr_t)va_arg(ap, char *);
			else if (ft_strchr("id", f.conversion))
				f.int_value = va_arg(ap, int);
			else if (ft_strchr("uxX", f.conversion))
				f.int_value = (long long)va_arg(ap, unsigned int);
			else if (f.conversion != '%')
				return (-1);
			central_arrange(f);
			st += skip_str(st, f);
		}
		else
		{
			count += write(1, st, 1);
			st++;
		}
		//st += (*st ? 1 : 0);
	}
	//write(1, "\0", 1);
	va_end(ap);
	return (count);
}
