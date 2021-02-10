#include "srcs/printf.h"
#include "Libft/Libft.h"
#include <stdio.h>

//static char *s_hidden = "hi low\0don't print me lol\0";

int main(void)
{
	printf("{%05.*d}", -15, 42);
	printf("\n");
	ft_printf("{%05.*d}", -15, 42);
	printf("\n");
}