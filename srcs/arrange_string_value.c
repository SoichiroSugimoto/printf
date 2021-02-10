/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_string_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:09:19 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/10 17:08:04 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../Libft/Libft.h"

// void print_list(f_list f)
// {
// 	printf("f.flag --> %d\n", f.flag);
// 	printf("f.precise --> %d\n", f.precise);
// 	printf("f.field --> %d\n", f.field);
// 	printf("f.str_value --> %s\n", f.str_value);
// }

static int		get_digit(f_list f)
{
	int i;

	i = ft_strlen(f.str_value);
	if ((f.precise >= 0) && (i > f.precise))
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
	//printf("%d\n", f.field);
	if (f.flag == 0)
		blank = '0';
	if (f.str_value == NULL)
		f.str_value = "(null)";
	if (f.flag == 1)
	{
		while (j < get_digit(f))
		{
			count += write(1, &f.str_value[j], 1);
			j++;
		}
		while (i < (f.field - get_digit(f)))
		{
			count += write(1, &blank, 1);
			i++;
		}
	}
	else
	{
		while (i < (f.field - get_digit(f)))
		{
			count += write(1, &blank, 1);
			i++;
		}
		while (j < get_digit(f))
		{
			count += write(1, &f.str_value[j], 1);
			j++;
		}
	}
}

