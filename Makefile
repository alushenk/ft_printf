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

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

make_lib:
	@make -C libft/
make_obj: $(OBJ)
copy_lib:
	cp libft/libft.a $(NAME)

$(NAME): make_lib make_obj copy_lib
	ar -q $(NAME) $(OBJ)
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
