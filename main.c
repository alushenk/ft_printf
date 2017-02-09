#include "ft_printf.h"
#include <math.h>

void test_size()
{
	size_t size = 2147483645;
	char *s = ft_strnew(size);
	for (size_t i = 0; i < size; i++)
		s[i] = 'x';
	printf("g%d%s", 5, s);
}

void test_string()
{
	int b;

	char *format = "suka blyad: %025.*sdd\n";
	int precision = 5;

	b = ft_printf(format, precision, "n");
	printf("%d\n", b);
	b = printf(format, precision, "n");
	printf("%d\n", b);
}

void test_decimal()
{
	int b;
	size_t n = 5;
	//"%0 .1 025.15-+zddd\n"

	//"%020.0d vvv\n" - при пресижене ноль не надо ставить нули в начало
	char *format = "%-*.*lu vvv\n";
	int width = 20;
	int precision = 10;

	b = ft_printf(format, width, precision, n);
	printf("%d\n", b);
	//print_mem_bytes(&n, sizeof(n));

	b = printf(format, width, precision, n);
	printf("%d\n", b);
	//print_mem_bytes(&n, sizeof(n));
}
/*
void test_pointer()
{
	int a = 55;
	int b;
	int *ptr = &a;


	b = ft_printf("suka blyad:%*.8p", 40, ptr);
	printf("|||||||||\n");
	printf("%d\n", b);
	b = printf("suka blyad:%*.8p", 40, ptr);
	printf("|||||||||\n");
	printf("%d\n", b);
}
*/
int main(void)
{
	test_string();
	printf("\n");
	//test_printf();
	test_decimal();
	//test_pointer();
	//test_size();
	return 0;
}