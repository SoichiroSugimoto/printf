# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 15:57:14 by sosugimo          #+#    #+#              #
#    Updated: 2021/01/24 20:35:57 by sosugimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ${shell find ./srcs/*.c}
OBJS	= $(SRCS:.c=.o)
HEADER	= ./srcs/*.h
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C Libft
	cp Libft/Libft.a libftprintf.a
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re