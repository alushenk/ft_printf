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
}

void test_size()
{
	size_t size = 2147483647;
	char *s = ft_strnew(size);
	for (int i = 0; i < size - 1; i++)
	{
		if (i % 10)
			s[i] = 'x';
		else
			s[i] = '\n';
	}
	printf("%s", s);
}

int main()
{
	int a;
	int b;

	//a = printf("%ss%s\n", "111", "222");
	//printf("%d\n", a);

	b = ft_printf("%d", 50);
	printf("%d\n", b);

	test_printf();

	return 0;
}