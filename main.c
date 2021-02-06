#include "srcs/printf.h"
#include "Libft/Libft.h"
#include <stdio.h>


int main(void)
{
	int i;
	i = printf("this %i number", 17);
	printf("%d\n", i);
	printf("\n");
	i = printf("this %i number", -267);
	printf("%d\n", i);
	printf("\n");
	i = printf("this %i number", 0);
	printf("%d\n", i);
	printf("\n");
	i = printf("[%i]", -1);
	printf("%d\n", i);
	printf("\n");
	i = printf("this %d number", 17);
	printf("%d\n", i);
	printf("\n");
	i = printf("this %d number", -267);
	printf("%d\n", i);
	printf("\n");
	i = printf("this %d number", 0);
	printf("%d\n", i);
	printf("\n");
	i = printf("[%7i]", -14);
	printf("%d\n", i);
	printf("\n");
	i = printf("[%5i]", -2562);
	printf("%d\n", i);
	printf("\n");
	i = printf("[%4i]", -2464);
	printf("%d\n", i);
	printf("\n");
	i = printf("[%-7i]", 33);
	printf("%d\n", i);
	printf("\n");
	i = printf("[%-7i]", -14);
	printf("%d\n", i);
	printf("\n");
	i = printf("[%-3i]", 0);
	printf("%d\n", i);
	printf("\n");
	i = printf("[%-5i]", -2562);
	printf("%d\n", i);
	printf("\n");

	printf("\n======================\n\n");

	i = ft_printf("this %i number", 17);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("this %i number", -267);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("this %i number", 0);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("[%i]", -1);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("this %d number", 17);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("this %d number", -267);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("this %d number", 0);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("[%7i]", -14);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("[%5i]", -2562);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("[%4i]", -2464);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("[%-7i]", 33);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("[%-7i]", -14);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("[%-3i]", 0);
	printf("%d\n", i);
	printf("\n");
	i = ft_printf("[%-5i]", -2562);
	printf("%d\n", i);
	printf("\n");
}