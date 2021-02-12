/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_string_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:09:19 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:50:42 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static	int		get_digit(t_list f)
{
	int		i;

	i = ft_strlen(f.str_value);
	if ((f.precise >= 0) && (i > f.precise))
		i = f.precise;
	return (i);
}

static	void	put_string_value(t_list f)
{
	int j;

	j = 0;
	if (f.flag == 1)
	{
		while (j < get_digit(f))
		{
			g_count += write(1, &f.str_value[j], 1);
			j++;
		}
	}
	else
	{
		while (j < get_digit(f))
		{
			g_count += write(1, &f.str_value[j], 1);
			j++;
		}
	}
}

void			arrange_string_value(t_list f)
{
	int		i;
	char	blank;

	i = 0;
	blank = (f.flag == 0 ? '0' : ' ');
	if (f.str_value == NULL)
		f.str_value = "(null)";
	if (f.flag == 1)
	{
		put_string_value(f);
		while (i < (f.field - get_digit(f)))
		{
			g_count += write(1, &blank, 1);
			i++;
		}
	}
	else
	{
		while (i < (f.field - get_digit(f)))
		{
			g_count += write(1, &blank, 1);
			i++;
		}
		put_string_value(f);
	}
}
