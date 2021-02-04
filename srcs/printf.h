/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:20:59 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/03 18:26:48 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	flag_list
{
	int			flag;
	int			f_flag;
	int			field;
	int			precise;
	int			p_flag;
	char		conversion;
	int			int_value;
	void		*str_value;
	char		char_value;
	uintptr_t	adr_value;
}				f_list;

int					ft_printf(const char *st, ...);
void				central_arrange(f_list f);
void				arrange_string_value(f_list f);
void				arrange_sign_value(f_list f);
void				arrange_num_value(f_list f);
void				arrange_value(f_list f);
void				arrange_numx_value(f_list f);
char				*into_hex(long long n, int prm);
void				arrange_nump_value(f_list f);
f_list				get_struct(const char *st);
f_list				ft_get_flag(const char *st, f_list f);
f_list				ft_init_flag(void);
int					sub_get_digit(const char *st);

// int				skip_str(const char *st, f_list f);
// char				*into_hex(long long n, int prm);
// char				refer_tab(long long i);
// char				refer_tabx(long long i);
// char				*itocx(long long n, char *p, int i, int prm);
// int				get_digitx(long long n);
// f_list			get_struct(const char *st);
// int				get_number(const char *st);
// f_list			ft_init_flag(f_list f);
// f_list			ft_get_flag(const char *st, f_list f);
//char				*arrange_value(f_list f);
//char				*arrange_value_c(f_list f, char *p, int size);
//char				*space_alooc(f_list f);
//int				get_realm(f_list f);
//int				get_length(f_list f);
//char				*arrange_num_value(f_list f);
//char				*ft_calloc2(f_list f);
//char				*ft_calloc2_minus(char *p, int n, int length);
//char				*space_alooc2(f_list f);
//int				get_length_num(f_list f);
//int				get_realm_num(f_list f);
//char				*cpy_n_str(void *dst, const void *src, int start, int n);
//char				*arrange_numx_value(f_list f);
// char				*ft_calloc2x(f_list f);
// char				*space_alooc2x(f_list f);
// int				get_length_numx(f_list f);
// int				get_realm_numx(f_list f);
// char				*arrange_nump_value(f_list f);
// char				*space_alooc2p(f_list f);
// int				get_realm_nump(f_list f);
// int				get_digit_hex(int n);
//char				*arrange_sign_value(f_list f);
//char 				*space_zero_alloc(f_list f);

#endif
