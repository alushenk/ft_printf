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

SRC  =  src/cast.c \
        src/format.c \
        src/ft_printf.c \
        src/functions.c \
        src/output.c \
        src/parsing.c \
        src/wchar.c \

OBJ = $(SRC:.c=.o)

LIB_OBJ = ./libft/libft.a

HEAD = src/ft_printf.h libft/libft.h

CFLAGS = -Wall -Wextra -Werror

make_lib:
	@make -C libft/
make_obj: $(OBJ)

all: $(NAME)
$(NAME): make_lib make_obj
	@echo "archiving ft_printf with libft objects"
	@ar rc $(NAME) $(OBJ) $(LIB_OBJ)
	@echo "indexing libftprintf.a"
	@ranlib $(NAME)

%.o: %.c $(HEAD)
	@gcc -c -o $@ $< $(CFLAGS)

clean:
	@echo "cleaning libft directory:"
	@make clean -C libft/
	@echo "removing ft_printf objects from src.."
	@rm -rf src/$(OBJ)

fclean: clean
	@make fclean -C libft/
	@echo "removing libftprintf.a"
	@rm -rf $(NAME)
re: fclean all
