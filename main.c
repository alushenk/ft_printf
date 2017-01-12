#include "ft_printf.h"
#include <math.h>

void test_printf()
{
	printf( "%0*x", 8, 15 );

	printf("\n");

	printf("%6i",100);

	printf("\n");

	printf("%.5s=%0*.*f", "value trash", 10, 5, M_PI);
}

int main()
{
	int a;
	int b;

	//a = printf("%ss%s\n", "111", "222");
	//printf("%d\n", a);

	//b = ft_printf("%d", 50);


	test_printf();

	return 0;
}