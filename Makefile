# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alushenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 16:42:07 by alushenk          #+#    #+#              #
#    Updated: 2017/02/09 16:42:59 by alushenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC  =  src/wchar.c \
		src/cast.c \
        src/format.c \
        src/ft_printf.c \
        src/functions.c \
        src/output.c \
        src/parsing.c

OBJ = $(SRC:.c=.o)

LIB_OBJ = $(shell ar -t libft/libft.a | if [ "$1" != "ft_memset.c \" ]; then 'NR != 1' fi | sed -e 's/^/libft\//')

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

make_lib:
	@make -C libft/
make_obj: $(OBJ)

$(NAME): make_lib make_obj
	ar rc $(NAME) $(OBJ) $(LIB_OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -c -o $@ $< $(CFLAGS)

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
