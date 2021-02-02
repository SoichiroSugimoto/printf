/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_sign_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:21:32 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/01 18:34:47 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/Libft.h"
#include "printf.h"

static void	put_set(f_list f)
{
	int i;
	char set;

	i = 0;
	set = ' ';
	if (f.flag == 1)
	{
		i = 1;
		while(i <= f.field - 1)
		{
			write(1, &set, 1);
			i++;
		}
	}
	else
	{
		if (f.flag == 0)
			set = '0';
		while(i <= f.field - 2)
		{
			write(1, &set, 1);
			i++;
		}
	}
}

void	arrange_sign_value(f_list f)
{
	int i;
	char c;
	char set;

	i = 0;
	c = '%';
	set = ' ';
	if (f.flag == 1)
	{
		write(1, &c, 1);
		i++;
		put_set(f);
	}
	else
	{
		put_set(f);
		write(1, &c, 1);
	}
}
