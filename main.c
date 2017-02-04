#include "ft_printf.h"
#include <math.h>

void test_printf()
{
	printf( "%0*x\n", 8, 15 );
	printf("\n");

	printf("%6i\n",100);
	printf("\n");

	printf ("Hi %c %d %s", 'c', 10, "there!\n");
	printf("\n");

	printf("%.5s=%0*.*f\n", "value trash", 10, 5, M_PI);
	printf("\n");

	float a = -5.05;
	printf("% *.*f", 15, 4, a);
	printf("|||||||||\n");
	printf("\n");

	int	c = -6;
	char *b = "suka blyad";
	printf("|||||||||");
	printf("% i", c);
	printf("|||||||||\n");
	printf("\n");

	const double RENT = 3852.99;
	//оно блять еще и округляет само)))
	printf("*%8f*\n", RENT);
	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3E*\n", RENT);
	printf("*%+4.2f*\n", RENT);
	printf("\n");

	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d% d **\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
	printf("\n");

	#define BLURB "Authentic imitation!"

	printf("[%2s]\n", BLURB);
	printf("[%24s]\n", BLURB);
	printf("[%24.5s]\n", BLURB);
	printf("[%-24.5s]\n", BLURB);
	printf("\n");

	//n помещает колличество выведенных до него символов в переменную
	//целого типа, на которую указывает аргумент
	int i;
	printf ("this is a test %n \n", &i);
	printf("%d\n", i);
	printf("\n");

	//в стандарте C99(что бы это не значило) не поддерживается $
	//так шо хуйня®
	int width = 5;
	int num = 2;
	printf("%*d\n", width, num);
	printf("%2$*1$d\n", width, num);
	printf("\n");

	//printf("%0*s\n", INT_MAX, "1234");

	printf("%**.*.*s\n", 1, 10, -2 , 1, "abc");
	printf("%**.*f\n", 1, 10, -2, 1.3333);
	printf("%*.2s\n", 10, "abc");
	printf("\n");

	int d = printf("%0*.*d", 10, 1, 33);
	printf("\n%d", d);
}

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
	int a;
	int b;

	char *format = "suka blyad: %010.20sdd\n";

	b = ft_printf(format, "nahuy");
	printf("%d\n", b);
	b = printf(format, "nahuy");
	printf("%d\n", b);
}

void test_decimal()
{
	int b;
	size_t n = 4294967296;
	char *format = "%+025.20zddd\n";

	b = ft_printf(format, n);
	printf("%d\n", b);
	print_mem_bytes(&n, sizeof(n));

	b = printf(format, n);
	printf("%d\n", b);
	print_mem_bytes(&n, sizeof(n));
}

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

int main(void)
{
	test_string();
	//test_printf();
	test_decimal();
	//test_pointer();
	//test_size();
	return 0;
}