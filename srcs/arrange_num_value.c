/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_num_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:56:05 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/04 15:55:11 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../Libft/Libft.h"

// void print_list(f_list f)
// {
// 	printf("\nf.flag --> %d\n", f.flag);
// 	printf("f.precise --> %d\n", f.precise);
// 	printf("f.field --> %d\n", f.field);
// 	printf("f.conversion --> %c\n", f.conversion);
// 	printf("f.int_value --> %d\n", f.int_value);
// }

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
	i = f.precise;
	if (f.precise < digit)
		i = digit;
	if (i == -1)
		i = 0;
	return (i);
}

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
	num = f.field -get_width(f);
	// if (f.int_value < 0)
	// 	num = f.field - get_width(f) - 1;
	if ((f.int_value < 0) && f.flag == 0)
		write(1, &sign, 1);
	while (i < num)
	{
		write(1, &blank, 1);
		i++;
	}
	if ((f.int_value < 0) && f.flag == -1)
		write(1, &sign, 1);
}

static void put_zero(f_list f)
{
	int i;
	char zero;
	int digit;

	i = 0;
	zero = '0';
	digit = get_digit(f);
	while (i < f.precise - digit)
	{
		write(1, &zero, 1);
		i++;
	}
}

static void put_digit(f_list f)
{
	char *num;
	int digit;
	int i;
	char sign = '-';

	i = 0;
	if (f.int_value < 0)
		num = ft_itoa((-1) * f.int_value);
	else
		num = ft_itoa(f.int_value);
	digit = get_digit(f);
	if ((f.flag == 1) && (f.int_value < 0))
		write(1, &sign, 1);
	while (i <= digit)
	{
		write(1, &num[i], 1);
		i++;
	}
}

// static void arrange_num_minus_value(f_list f)
// {
// 	char sign;
// 	int digit;

// 	sign = '-';
// 	digit = get_digit(f);
// 	if (f.flag == 1)
// 	{
// 		if ((f.flag == 0) && ((f.precise >= f.precise) || (f.precise >= digit)))
// 			write(1, &sign, 1);
// 		if ((f.flag != 0) && ((f.field >= f.precise) || (f.precise >= digit)))
// 			write(1, &sign, 1);
// 		put_zero(f);
// 		if ((digit >= f.field) && (digit >= f.precise))
// 			write(1, &sign, 1);
// 		if ((f.flag != 0) && !((f.field >= f.precise) && (f.precise > digit)))
// 			write(1, &sign, 1);
// 		put_digit(f);
// 		// if ((f.flag == 0) && ((f.field >= f.precise) || (f.field >= digit)))
// 		// 	write(1, &sign, 1);
// 		put_blank(f);
// 	}
// 	else
// 	{
// 		if ((f.flag == 0) && ((f.field >= f.precise) || (f.field >= digit)))
// 			write(1, &sign, 1);
// 		put_blank(f);
// 		if ((f.flag == 0) && ((f.precise >= f.precise) || (f.precise >= digit)))
// 			write(1, &sign, 1);
// 		if ((f.flag != 0) && ((f.field >= f.precise) || (f.precise >= digit)))
// 			write(1, &sign, 1);
// 		put_zero(f);
// 		if ((digit >= f.field) && (digit >= f.precise))
// 			write(1, &sign, 1);
// 		if ((f.flag != 0) && !((f.field >= f.precise) && (f.precise > digit)))
// 			write(1, &sign, 1);
// 		put_digit(f);
// 	}
// }

void	arrange_num_value(f_list f)
{
	// if (f.int_value < 0)
	// 	arrange_num_minus_value(f);
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
	// printf("]");
	// print_list(f);
}

/*
void arrange_num_utils(f_list f)
{
	int digit = 5;
	if ((f.flag == 0) && ((f.field >= f.precise) || (f.field >= digit)))
	{
		//fieldの直前に'-'を置く
	}
	else if ((f.flag == 0) && ((f.precise >= f.precise) || (f.precise >= digit)))
	{
		//preciseの直前に'-'を置く
	}
	else if ((f.flag != 0) && ((f.field >= f.precise) || (f.precise >= digit)))
	{
		//preciseの直前に'-'を置く
	}
	else if ((digit >= f.field) && (digit >= f.precise))
	{
		//digitの直前に'-'を置く
	}
	else if ((f.flag != 0) && !((f.field >= f.precise) && (f.precise > digit)))
	{
		//digitの直前に'-'を置く
	}

}
*/