/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:03:55 by sosugimo          #+#    #+#             */
/*   Updated: 2020/12/11 02:57:04 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
#include "Libft/Libft.h"

void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c)；

#endif