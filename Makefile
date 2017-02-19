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

SRC =   ft_printf.c \
        functions.c \
        format.c \
        output.c \
        parsing.c \
        wchar.c \
        cast.c

OBJ = $(SRC:.c=.o)

LIB_PATH = ../../LIBFT/

LIBOBJ = $(LIB_PATH)*.o

HEAD = -I ft_printf.h

CFLAGS = -c -Wall -Wextra -Werror

LIBINC = -I $(LIB_PATH)libft.h -L.$(LIB_PATH) -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
	ar rc $(NAME) $(OBJ) $(LIBOBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(HEAD) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all
