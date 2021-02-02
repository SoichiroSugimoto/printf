/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_numx_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 01:54:19 by sosugimo          #+#    #+#             */
/*   Updated: 2021/01/31 23:51:16 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/Libft.h"
#include "printf.h"

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
	digit = (int)ft_strlen(into_hex(f.int_value, 0));
	while (i <= f.precise - digit)
	{
		write(1, &zero, 1);
		i++;
	}
}

void	arrange_numx_value(f_list f)
{
	int i;
	char zero;
	int digit;
	char *num;

	i = 0;
	zero = '0';
	digit = (int)ft_strlen(into_hex(f.int_value, 0));
	if (f.conversion == 'x')
		num = into_hex(f.int_value, 0);
	else
		num = into_hex(f.int_value, 1);
	put_blank(f);
	put_zero(f);
	while (i <= digit)
	{
		write(1, &num[i], 1);
		i++;
	}
}
