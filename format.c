#include "ft_printf.h"

void	format_num_prefix(t_format *format)
{
	if (!ft_strncmp(format->sufix, "0\0", 2) && format->precision == 0)
		format->sufix[0] = ' ';
	if (format->num_prefix[0] == 0 && (format->flag & SIGNED))
	{
		if (format->flag & PLUS)
			format->num_prefix[0] = '+';
		else if (format->flag & SPACE)
			format->num_prefix[0] = ' ';
		if (format->sufix[0] == ' ')
		{
			ft_strcpy(format->sufix, format->num_prefix);
			ft_bzero(format->num_prefix, 2);
		}
	}
	if (format->flag & HASH)
	{
		if (format->base == 16)
		{
			format->num_prefix[0] = '0';
			format->num_prefix[1] = (format->type == 'X') ? 'X' : 'x';
		}
		if (format->base == 8)
			format->num_prefix[0] = '0';
	}
}

void	format_num(t_format *format)
{
	ssize_t len;
	ssize_t	i;
	char	*str;

	len = (format->precision > format->sufix_len) ? format->precision : format->sufix_len;
	if (format->precision == -1 && format->width > len && !(format->flag & LEFT))
		len = format->width;
	i = 0;
	if (format->base == 16 && (format->flag & HASH))
		len += 2;
	str = ft_strnew(len + 1);
	while(format->num_prefix[i])
	{
		str[i] = format->num_prefix[i];
		i++;
	}
	while(format->sufix_len < (len - i))
	{
		str[i] = '0';
		i++;
	}
	format->sufix_len += i;
	ft_strcpy(str + i, format->sufix);
	free(format->sufix);
	format->sufix = str;
}

void 	format_string(t_format *format)
{
	int		c;
	ssize_t	i;
	ssize_t len;
	char	*str;
	char 	*temp;

	if ((len = format->width - format->sufix_len) <= 0 || format->width < format->precision)
		return;
	format->sufix_len += len;
	c = (format->flag & ZEROPAD && !(format->flag & LEFT)) ? '0' : ' ';
	if (format->type != 'S' && format->type != 's' && format->precision != -1)
		c = ' ';
	str = ft_strnew(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		str[i] = (char)c;
		i++;
	}
	temp = ft_strdup(format->sufix);
	free(format->sufix);
	if (format->flag & LEFT)
		format->sufix = ft_strjoin(temp, str);
	else
		format->sufix = ft_strjoin(str, temp);
	free(temp);
}