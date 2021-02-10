/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_num_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:56:05 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/10 19:17:37 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../Libft/Libft.h"

static int get_digit(f_list f)
{
	char *num;
	int digit;

	if (f.int_value < 0)
		num = ft_itoa((-1) * f.int_value);
	else
		num = ft_itoa(f.int_value);
	digit = (int)ft_strlen(num);
	return (digit);
}

static int get_width(f_list f)
{
	int i;
	int digit;

	digit = (int)ft_strlen(ft_itoa(f.int_value));
	i = f.precise + (f.int_value < 0 ? 1 : 0);
	if (f.precise < digit)
		i = digit;
	if (i == -1 || (f.precise == 0 && f.int_value == 0))
		i = 0;
	return (i);
}

//*が存在している。(f.p_flag == 1)&& preciseがマイナス値　--> preciseを無視

static void put_blank(f_list f)
{
	int i;
	char blank;
	int num;
	char sign = '-';

	i = 0;
	blank = ' ';
	if (f.flag == 0)
		blank = '0';
	num = f.field - get_width(f);
	if ((f.int_value < 0) && f.flag == 0)
		count += write(1, &sign, 1);
	while (i < num)
	{
		count += write(1, &blank, 1);
		i++;
	}
}

static void put_zero(f_list f)
{
	int i;
	char zero;
	int digit;

	i = 0;
	zero = '0';
	digit = get_digit(f);
	if (f.flag != 0 && f.int_value < 0)
		count += write(1, "-", 1);
	while (i < f.precise - digit)
	{
		count += write(1, &zero, 1);
		i++;
	}
}

static void put_digit(f_list f)
{
	char *num;
	int digit;
	int i;

	i = 0;
	if (f.precise == 0 && f.int_value == 0)
		return;
	if (f.int_value < 0)
		num = ft_itoa((-1) * f.int_value);
	else
		num = ft_itoa(f.int_value);
	digit = get_digit(f);
	while (i < digit)
	{
		count += write(1, &num[i], 1);
		i++;
	}
}

void	arrange_num_value(f_list f)
{
	if (f.flag == 1)
	{
		put_zero(f);
		put_digit(f);
		put_blank(f);
	}
	else
	{
		put_blank(f);
		put_zero(f);
		put_digit(f);
	}
}
