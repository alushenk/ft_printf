#include "ft_printf.h"
#include <math.h>
#include <locale.h>

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

	char *format = "%4.s";
	char *string = "42";

	b = ft_printf(format, string);
	printf("\n%d\n", b);
	b = printf(format, string);
	printf("\n%d\n", b);
}

void test_decimal()
{
	int b;
	size_t n = 9223372036854775807;
	//"%0 .1 025.15-+zddd\n"
	//"%020.0d vvv\n" - при пресижене ноль не надо ставить нули в начало
	//"%20.15d\n", 54321
	char *format = "%jd\n";
	int width = 20;
	int precision = 3;

	b = ft_printf(format, n);
	printf("%d\n", b);
	//print_mem_bytes(&n, sizeof(n));

	b = printf(format, n);
	printf("%d\n", b);
	//print_mem_bytes(&n, sizeof(n));
}

void test_pointer()
{
	int a = 55;
	int b;
	int *ptr = &ft_printf;
	//char *format = "%.0p, %.p";
	char *format = "%p\n";

	b = ft_printf(format, &ft_printf);
	printf("|||||||||\n");
	printf("%d\n", b);
	b = printf(format, &ft_printf);
	printf("|||||||||\n");
	printf("%d\n", b);
}

void test_basic()
{
	int d;
	char *str = NULL;
	char *format = "t%[\n";
	int precision = -6;

	d = ft_printf(format, precision, str);
	printf("%d\n", d);

	d = printf(format, precision, str);
	printf("%d\n", d);
}

void test_42()
{
	int d;
	int num1 = 255;
	char *format = "%c";

	d = ft_printf(format, num1);
	printf("\n%d\n", d);

	d = printf(format, num1);
	printf("\n%d\n", d);
}

void test_char()
{

	int d;
	int num1 = 0;
	wint_t num2 = L'ø';

	char *format = "%C";

	d = ft_printf(format, num2);
	printf("\n%d\n", d);

	d = printf(format, num2);
	printf("\n%d\n", d);
}

void test_wchar()
{

	int d;
	int num1 = 0;
	char c = 'c';
	wchar_t* num2 = L"ÊÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B";
	char *format = "%S";
	int precision = 0;

	d = ft_printf(format, num2);
	printf("\n%d\n", d);

	d = printf(format, num2);
	printf("\n%d\n", d);
}

void test_octal()
{
	int b;
	char *format = "%#o";
	size_t n = 0;
	int width = 20;
	int precision = 3;

	b = ft_printf(format, n);
	printf("\n%d\n", b);

	b = printf(format, n);
	printf("\n%d\n", b);
}


int main(void)
{
	//setlocale(LC_ALL, "");

	//test_string();
	//printf("\n");
	//test_decimal();
	//printf("\n");
	//test_pointer();
	//printf("\n");
	//test_size();
	//printf("\n");
	//test_basic();
	//printf("\n");
	test_42();
	printf("\n");
	test_char();
	printf("\n");
	//test_octal();
	//printf("\n");
	test_wchar();
	return 0;
}