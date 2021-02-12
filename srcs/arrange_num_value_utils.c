/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_num_value_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 01:38:03 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:50:24 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int			get_width(t_list f)
{
	int		i;
	int		digit;

	digit = (int)ft_strlen(ft_itoa(f.int_value));
	i = f.precise + (f.int_value < 0 ? 1 : 0);
	if (f.precise < digit)
		i = digit;
	if (i == -1 || (f.precise == 0 && f.int_value == 0))
		i = 0;
	return (i);
}

int			get_width_hex(t_list f)
{
	int		i;
	int		digit;

	digit = (int)ft_strlen(into_hex(f.int_value, 0));
	i = f.precise + (f.int_value < 0 ? 1 : 0);
	if (f.precise < digit)
		i = digit;
	if (i == -1 || (f.precise == 0 && f.int_value == 0))
		i = 0;
	return (i);
}

int			get_digit_p(t_list f)
{
	char	*num;
	int		digit;

	if (f.precise == 0 && f.adr_value == 0)
		return (0);
	if (f.adr_value < 0)
		num = into_p_hex((-1) * f.adr_value, 0);
	else
		num = into_p_hex(f.adr_value, 0);
	digit = (int)ft_strlen(num);
	return (digit);
}

int			get_width_p(t_list f)
{
	int		i;
	int		digit;

	if (f.precise == 0 && f.adr_value == 0)
		return (2);
	digit = (int)ft_strlen(into_p_hex(f.adr_value, 0)) + 2;
	i = f.precise + (f.adr_value < 0 ? 1 : 0);
	if (f.precise < digit)
		i = digit;
	if (i == -1 || (f.precise == 0 && f.adr_value == 0))
		i = 0;
	return (i);
}
