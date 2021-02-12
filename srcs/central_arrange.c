/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_arrange.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:42:59 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:50:51 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	central_arrange(t_list f)
{
	if (f.conversion == 'c')
		arrange_value(f);
	else if (f.conversion == 's')
		arrange_string_value(f);
	else if (f.conversion == 'd')
		arrange_num_value(f);
	else if (f.conversion == 'i')
		arrange_num_value(f);
	else if (f.conversion == 'u')
		arrange_num_value(f);
	else if (f.conversion == 'x')
		arrange_numx_value(f);
	else if (f.conversion == 'X')
		arrange_numx_value(f);
	else if (f.conversion == 'p')
		arrange_nump_value(f);
	else
		arrange_sign_value(f);
}
