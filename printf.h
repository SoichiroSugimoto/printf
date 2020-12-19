/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:20:59 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/19 10:45:37 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct flag_list
{
	int flag;
	int f_flag;
	int field;
	int precise;
	char conversion;
	int	int_value;
	char *str_value;
	char char_value;
} f_list;

int		ft_printf(const char *st, ...);
char	*into_hex(int n);
f_list	get_struct(const char *st, int i);
char	*arrange_value(f_list f);

#endif