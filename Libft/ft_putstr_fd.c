/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:10:57 by sosugimo          #+#    #+#             */
/*   Updated: 2021/01/04 19:18:06 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i] && fd)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
