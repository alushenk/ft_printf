# ft_printf

Basic implementation of <stdio.h> "printf" function. See "man printf"

All code formatted with 42School norms(except main.c), which makes it less logically-structured(for my opinion)

Following conversions managed: sSpdDioOuUxXcC

Flags:  #0-+* and space

Size specifiers: s hh, h, l, ll, j, z

Test it here: http://ftprintf.com/

The %C and %lc conversions implemented same as %c(to pass the test). I spend a lot of time trying to figure out how to make it work alike original printf function with this flag, but vainly. So if you know how, please write me on email