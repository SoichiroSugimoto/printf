/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:19:05 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/11 02:50:12 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/Libft.h"
#include <stdio.h>
#include <string.h>

char *ft_putchar(char *st)
{
	int i;

	i = 0;
	while (st[i])
	{
		write(1, &st[i], 1);
		i++;
	}
	return (0);
}



int ft_printf(const char *st , ...)
{
	int i;
	char *sub;
	va_list ap;

	i = 0;
	va_start(ap, st);
	while (st[i])
	{
		if (st[i] == '%')
		{
			i++;
			i++;
			sub = va_arg(ap, char*);
			ft_putchar(sub);
		}
		write(1, &st[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	char *st = "apple";
	printf("%lu\n",ft_strlen(st));
	ft_printf("this is %s I made\n", "string");
}

//int printf(const char * restrict format, ...);

// void va_start(va_list ap, last);
// type va_arg(va_list ap, type);
// void va_copy(va_list dest, va_list src);
// void va_end(va_list ap);


// malloc
// free
// write
// va_start
// va_arg
// va_copy
// va_end