//
// Created by Anton Lushenko on 2/2/17.
//

void print_mem_bytes(void *adress, ssize_t size)
{
	char *ptr;
	int buf;
	int mask;

	ptr = (char*)adress;
	ft_putstr("| ");
	while (--size >= 0)
	{
		buf = ptr[size];
		mask = 128;
		while (mask != 0)
		{
			if (buf & mask)
				ft_putchar('1');
			else
				ft_putchar('0');
			mask >>= 1;
		}
		ft_putstr(" | ");
	}
	ft_putchar('\n');
}