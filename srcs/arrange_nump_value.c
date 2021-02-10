/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_nump_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:02:45 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/10 12:03:39 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/Libft.h"
#include "printf.h"

static void	 put_front()
{
	char *front;

	front = "0x";
	count += write(1, &front[0], 1);
	count += write(1, &front[1], 1);
}

static int get_digit(f_list f)
{
	char *num;
	int digit;

	// if (f.adr_value == 0)
	// 	return (1);
	if (f.precise == 0 && f.adr_value == 0)
		return (0);
	if (f.adr_value < 0)
		num = into_hex((-1) * f.adr_value, 0);
	else
		num = into_hex(f.adr_value, 0);
	digit = (int)ft_strlen(num);
	//printf("(%lu)\n", f.adr_value);
	return (digit);
}

static int get_width(f_list f)
{
	int i;
	int digit;

	// if (f.adr_value == 0)
	// 	return (3);
	if (f.precise == 0 && f.adr_value == 0)
		return (2);
	digit = (int)ft_strlen(into_hex(f.adr_value, 0)) + 2;
	i = f.precise + (f.adr_value < 0 ? 1 : 0);
	if (f.precise < digit)
		i = digit;
	if (i == -1 || (f.precise == 0 && f.adr_value == 0))
		i = 0;
	return (i);
}

static void put_blank(f_list f)
{
	int i;
	char blank;
	int num;
	// char sign = '-';

	i = 0;
	blank = ' ';
	if (f.flag == 0)
		blank = '0';
	num = f.field - get_width(f);
	// if ((f.adr_value < 0) && f.flag == 0)
	// 	count += write(1, &sign, 1);
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
	put_front();
	// if (f.flag != 0 && f.adr_value < 0)
	// 	count += write(1, "-", 1);
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
	if (f.precise == 0 && f.adr_value == 0)
		return;
	num = into_hex(f.adr_value, 0);
	// if (f.adr_value < 0)
	// 	num = into_hex((-1) * f.adr_value);
	// else
	// 	num = into_hex(f.adr_value);
	digit = get_digit(f);
	while (i < digit)
	{
		count += write(1, &num[i], 1);
		i++;
	}
}

void	arrange_nump_value(f_list f)
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




/*
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
*/
