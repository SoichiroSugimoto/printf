/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:20:59 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/13 01:44:04 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	int			flag;
	int			f_flag;
	int			field;
	int			precise;
	int			p_flag;
	char		conversion;
	long long	int_value;
	void		*str_value;
	char		char_value;
	uintptr_t	adr_value;
}					t_list;

int					g_count;

int					ft_printf(const char *st, ...);
void				central_arrange(t_list f);
void				arrange_string_value(t_list f);
void				arrange_sign_value(t_list f);
void				arrange_num_value(t_list f);
void				arrange_value(t_list f);
void				arrange_numx_value(t_list f);
char				*into_hex(long long n, int prm);
char				*into_p_hex(uintptr_t n, int prm);
void				arrange_nump_value(t_list f);
t_list				get_struct(const char *st);
t_list				ft_get_flag(const char *st, t_list f);
t_list				ft_init_flag(void);
int					sub_get_digit(const char *st);
int					get_width(t_list f);
int					get_width_hex(t_list f);
int					get_digit_p(t_list f);
int					get_width_p(t_list f);

#endif
