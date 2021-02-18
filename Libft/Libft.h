/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 02:25:04 by sosugimo          #+#    #+#             */
/*   Updated: 2021/02/19 00:20:09 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_itoa(long long n);
int			ft_atoi(const char *str);

#endif
