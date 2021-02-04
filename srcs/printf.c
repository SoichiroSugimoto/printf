/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:19:05 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/02 16:37:27 by sosugimo         ###   ########.fr       */
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

int				ft_printf(const char *st, ...)
{
	f_list	f;
	va_list	ap;

	va_start(ap, st);
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
		}
		write(1, st, 1);
		st += (*st ? 1 : 0);
	}
	va_end(ap);
	return (ft_strlen(st));
}
