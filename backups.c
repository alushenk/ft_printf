//
// Created by Anton Lushenko on 1/19/17.
//
#include "ft_printf.h"

/*
char *check_size(char **fmt, va_list ap)
{
	char *str;
	char *result;

	result = NULL;
	str = *fmt;
	if (*str == 'h')
		result = ft_strdup("h");
	if (!strncmp(str, "hh", 2))
		result = ft_strdup("hh");
	if (*str == 'l')
		result = ft_strdup("l");
	if (!strncmp(str, "ll", 2))
		result = ft_strdup("ll");
	if (*str == 'j')
		result = ft_strdup("j");
	if (*str == 'z')
		result = ft_strdup("z");
	if (!result)
		return (NULL);
	str += ft_strlen(result);
	*fmt = str;
	return (result);
}
 */

/*
void initialise_array(void (*foo[])(t_format* , va_list))
{
	foo[0] = &write_d_h;
	foo[1] = &write_d_hh;

}
*/

/*
void write_decimal(t_format *format, va_list ap)
{
	int num;
	size_t i;
	void (*foo[6])(t_format *a, va_list b);

	initialise_array(foo);
	i = 0;
	num = 0;
	while(!(format->size & (1 << i)) && i < 6)
		i++;
	if (i == 6)
		num = (int) va_arg (ap, int);
	else
		foo[i](format, ap);
}
*/

/*
	result = (format->size & LL) ? (long long) va_arg(ap, long long) :
			 (format->size & L) ? (long) va_arg(ap, long) :
			 (format->size & H) ? (short) va_arg(ap, short) :
			 (format->size & HH) ? (char) va_arg(ap, char) :
			 (int) va_arg(ap, int);
*/
/*
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

 */