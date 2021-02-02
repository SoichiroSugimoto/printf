/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:03:55 by sosugimo          #+#    #+#             */
/*   Updated: 2021/01/04 19:19:29 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memcpy2(void *dst, const void *src, int n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
