#include "srcs/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

//static char *s_hidden = "hi low\0don't print me lol\0";

int main(void)
{
	ft_printf("this is sting : [%23.10s]", "this is an apple");
	printf("\n");
	printf("this is sting : [%23.10s]", "this is an apple");
	printf("\n");
}