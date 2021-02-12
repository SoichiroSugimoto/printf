/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:15:00 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:50:47 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static	void	put_set(t_list f)
{
	int		i;
	char	set;

	i = 0;
	set = ' ';
	if (f.flag == 1)
	{
		while (i < f.field - 1)
		{
			g_count += write(1, &set, 1);
			i++;
		}
	}
	else
	{
		while (i < f.field - 1)
		{
			g_count += write(1, &set, 1);
			i++;
		}
	}
}

void			arrange_value(t_list f)
{
	int		i;
	char	c;
	char	set;

	i = 0;
	c = f.char_value;
	set = ' ';
	if (f.flag == 1)
	{
		g_count += write(1, &c, 1);
		i++;
		put_set(f);
	}
	else
	{
		if (f.flag == 0)
			set = '0';
		put_set(f);
		g_count += write(1, &c, 1);
	}
}
