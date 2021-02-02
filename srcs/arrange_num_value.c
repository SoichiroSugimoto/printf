/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_num_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:56:05 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/01 17:41:26 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../Libft/Libft.h"

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
	while (i <= f.precise - digit)
	{
		write(1, &zero, 1);
		i++;
	}
}

void	arrange_num_value(f_list f)
{
	int i;
	int digit;
	char *num;

	i = 0;
	if (f.int_value < 0)
		num = ft_itoa((-1) * f.int_value);
	else
		num = ft_itoa(f.int_value);
	digit = (int)ft_strlen(ft_itoa(f.int_value));
	put_blank(f);
	put_zero(f);
	while (i <= digit)
	{
		write(1, &num[i], 1);
		i++;
	}
}
