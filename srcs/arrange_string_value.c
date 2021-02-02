/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_string_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:09:19 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/02 06:45:40 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../Libft/Libft.h"

static int		get_digit(f_list f)
{
	int i;

	i = ft_strlen(f.str_value);
	if ((f.precise != -1) && (i > f.precise))
		i = f.precise;
	return (i);
}

void	arrange_string_value(f_list f)
{
	int i;
	int j;
	char blank;

	i = 0;
	j = 0;
	blank = ' ';
	if (f.str_value == NULL)
		ft_putstr_fd("(null)", 1);
	else if (f.flag == 1)
	{
		while (i < (f.field - get_digit(f)))
		{
			write(1, &blank, 1);
			i++;
		}
		while (j < get_digit(f))
		{
			write(1, &f.str_value[j], 1);
			j++;
		}
	}
	else
	{
		while (i < (f.field - get_digit(f)))
		{
			write(1, &blank, 1);
			i++;
		}
		while (j < get_digit(f))
		{
			write(1, &f.str_value[j], 1);
			j++;
		}
	}
}
