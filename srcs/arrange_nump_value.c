/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_nump_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:02:45 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:50:28 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static	void		put_front(void)
{
	char	*front;

	front = "0x";
	g_count += write(1, &front[0], 1);
	g_count += write(1, &front[1], 1);
}

static	void		put_blank(t_list f)
{
	int		i;
	char	blank;
	int		num;

	i = 0;
	blank = ' ';
	if (f.flag == 0)
		blank = '0';
	num = f.field - get_width_p(f);
	while (i < num)
	{
		g_count += write(1, &blank, 1);
		i++;
	}
}

static	void		put_zero(t_list f)
{
	int		i;
	char	zero;
	int		digit;

	i = 0;
	zero = '0';
	digit = get_digit_p(f);
	put_front();
	while (i < f.precise - digit)
	{
		g_count += write(1, &zero, 1);
		i++;
	}
}

static	void		put_digit(t_list f)
{
	char	*num;
	int		digit;
	int		i;

	i = 0;
	if (f.precise == 0 && f.adr_value == 0)
		return ;
	num = into_p_hex(f.adr_value, 0);
	digit = get_digit_p(f);
	while (i < digit)
	{
		g_count += write(1, &num[i], 1);
		i++;
	}
}

void				arrange_nump_value(t_list f)
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
