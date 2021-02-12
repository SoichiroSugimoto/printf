/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_numx_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 01:54:19 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:50:32 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static	int		get_digit(t_list f)
{
	char	*num;
	int		digit;

	if (f.int_value < 0)
		num = into_hex((-1) * f.int_value, 0);
	else
		num = into_hex(f.int_value, 0);
	digit = (int)ft_strlen(num);
	return (digit);
}

static	void	put_blank(t_list f)
{
	int		i;
	char	blank;
	int		num;
	char	sign;

	i = 0;
	sign = '-';
	blank = ' ';
	if (f.flag == 0)
		blank = '0';
	num = f.field - get_width_hex(f);
	if ((f.int_value < 0) && f.flag == 0)
		g_count += write(1, &sign, 1);
	while (i < num)
	{
		g_count += write(1, &blank, 1);
		i++;
	}
}

static	void	put_zero(t_list f)
{
	int		i;
	char	zero;
	int		digit;

	i = 0;
	zero = '0';
	digit = get_digit(f);
	if (f.flag != 0 && f.int_value < 0)
		g_count += write(1, "-", 1);
	while (i < f.precise - digit)
	{
		g_count += write(1, &zero, 1);
		i++;
	}
}

static	void	put_digit(t_list f)
{
	char	*num;
	int		digit;
	int		i;

	i = 0;
	if (f.precise == 0 && f.int_value == 0)
		return ;
	num = into_hex(f.int_value, (f.conversion == 'x' ? 0 : 1));
	digit = get_digit(f);
	while (i < digit)
	{
		g_count += write(1, &num[i], 1);
		i++;
	}
}

void			arrange_numx_value(t_list f)
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
