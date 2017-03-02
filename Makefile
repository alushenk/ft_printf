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

OBJ  =  src/cast.o \
        src/format.o \
        src/ft_printf.o \
        src/functions.o \
        src/output.o \
        src/parsing.o \
        src/wchar.o \


LIB_OBJ = libft/*.o

HEAD = src/ft_printf.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

make_lib:
	@make -C libft/
make_obj: $(OBJ)

$(NAME): make_lib make_obj
	@echo "archiving ft_printf with libft objects"
	@ar rc $(NAME) $(OBJ) $(LIB_OBJ)
	@echo "indexing libftprintf.a"


%.o: %.c &(HEAD)
	@gcc $(CFLAGS) $(HEAD) -o $@ -c $<

clean:
	@echo "cleaning libft directory:"
	@make clean -C libft/
	@echo "removing ft_printf objects from src.."
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@echo "removing libftprintf.a"
	@rm -rf $(NAME)
re: fclean all
