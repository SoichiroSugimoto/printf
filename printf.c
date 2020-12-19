/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:19:05 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/18 22:18:03 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/Libft.h"
#include "printf.h"

int ft_printf(const char *st , ...)
{
	int i;
	f_list f;
	va_list ap;

	i = 0;
	va_start(ap, st);
	while (st[i])
	{
		if (st[i] == '%')
		{
			f = get_struct(&st[i], i);
			if (f.conversion == 'c')
				f.char_value = va_arg(ap, int);
			if (f.conversion == 's')
				f.str_value = va_arg(ap, char*);
			else
				f.int_value = va_arg(ap, int);
			if (f.f_flag == 1)
				f.field = va_arg(ap, int);
			ft_putstr_fd(arrange_value(f), 1);
		}
		write(1, &st[i], 1);
		i++;
	}
	va_end(ap);
	return (ft_strlen(st));
}


#include <stdio.h>
int main(void)
{
	// int i;
	// i = ft_printf("this is %s I made, but it is %s yet.\n", "string", "uncopleted");
	// printf("%d", i);
	// ft_printf("this is %s I made, but it is %s yet.\n", "string", "uncopleted");
	printf("%s\n", "this is string");
}



//int printf(const char * restrict format, ...);

// void va_start(va_list ap, last);
// type va_arg(va_list ap, type);
// void va_copy(va_list dest, va_list src);
// void va_end(va_list ap);