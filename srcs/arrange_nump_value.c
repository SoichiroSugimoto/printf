/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_nump_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:02:45 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/01 17:45:48 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/Libft.h"
#include "printf.h"

static void	 put_front()
{
	char *front;

	front = "0x";
	write(1, &front[0], 1);
	write(1, &front[1], 1);
}

static void put_blank(f_list f)
{
	int i;
	char blank;
	char sign;

	i = 0;
	blank = ' ';
	sign = '-';
	while (i <= f.field - f.precise)
	{
		write(1, &blank, 1);
		i++;
	}
	if (f.int_value < 0)
		write(1, &sign, 1);
}

static void put_zero(f_list f)
{
	int i;
	char zero;
	int digit;

	i = 0;
	zero = '0';
	digit = (int)ft_strlen(ft_itoa(f.int_value));
	while (i <= f.precise - digit - 2)
	{
		write(1, &zero, 1);
		i++;
	}
}

void	arrange_nump_value(f_list f)
{
	int i;
	char *p;
	int digit;

	i = 0;
	p = into_hex(f.adr_value, 0);
	digit = (int)ft_strlen(p);
	put_blank(f);
	put_zero(f);
	put_front();
	while (i != digit)
	{
		write(1, &p[i], 1);
		i++;
	}
}
