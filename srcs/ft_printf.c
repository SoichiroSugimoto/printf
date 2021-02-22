/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:19:05 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/22 19:32:35 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int			skip_str(const char *st, t_list f)
{
	int i;

	i = 1;
	while (st[i] && st[i] != f.conversion)
		i++;
	return (i + 1);
}

t_list		get_args(const char **st, va_list ap, t_list f)
{
	f = get_struct(*st);
	if (f.f_flag == 1)
		f.field = va_arg(ap, int);
	if ((f.field < 0 && f.field != -1) || (f.f_flag == 1 && f.field == -1))
	{
		f.flag = 1;
		f.field *= -1;
	}
	if (f.p_flag == 1)
		f.precise = va_arg(ap, int);
	if (f.p_flag == 1 && f.precise < 0)
		f.precise = -1;
	if (f.flag == 0 && f.precise >= 0 && f.conversion != '%')
		f.flag = -1;
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
	return (f);
}

int			ft_printf(const char *st, ...)
{
	t_list	f;
	va_list	ap;

	va_start(ap, st);
	g_count = 0;
	f = ft_init_flag();
	while (*st)
	{
		if (*st == '%')
		{
			f = get_args(&st, ap, f);
			if (*st && !(ft_strchr("cspdiuxX%", f.conversion)))
				return (-1);
			central_arrange(f);
			st += skip_str(st, f);
		}
		else
		{
			g_count += write(1, st, 1);
			st++;
		}
	}
	va_end(ap);
	return (g_count);
}
