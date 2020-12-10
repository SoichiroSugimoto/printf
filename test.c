#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

char ft_putstr(char *st)
{
	int i;

	i = 0;
	while (st[i])
	{
		write(1, &st[i], 1);
		i++;
	}
	return (0);
}

void testit (int i, ...)
{
	//動的引数部分がint型ならi=0。
	va_list argptr;
	va_list ap;
	va_start(argptr, i);

	if (i == 0)
	{
		//int n = va_arg(argptr, int);
		va_copy(ap, argptr);
		int m = va_arg(ap, int);
		printf("%d\n", m);
		int n = va_arg(argptr, int);
		printf("%d\n", n);
		m = va_arg(ap, int);
		printf("%d\n", m);
	}
	else if (i == 1)
	{
		double f = va_arg(argptr, double);
		printf("%a\n", f);
	}
	else
	{
		char *s = va_arg(argptr, char*);
		printf("%s\n", s);
	}

	va_end(argptr);
}

// int main()
// {
// 	//testit(0, 0xFFFFFFFF); // 1st problem: 0xffffffff is not an int
// 	testit(1, NULL);       // 2nd problem: NULL is not a char*
// 	testit(0, 3.141517);
// 	testit(2, "mojimoji");
// 	testit(0, 4, 2);


// 	printf("\nこれは、%sです。本当は%sです。\n","test","apple");
// }






void test_arg(int i, ...)
{
	va_list argptr;
	va_start(argptr, i);

	if (i == 0)
	{
		char *st = va_arg(argptr, char*);
		printf("%s\n", st);
		st = va_arg(argptr, char*);
		printf("%s\n", st);
	}

	va_end(argptr);
}

int main(void)
{
	test_arg(0, "this is string", "this is an apple");
}