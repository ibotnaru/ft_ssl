# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 23:12:26 by ibotnaru          #+#    #+#              #
#    Updated: 2019/11/13 02:19:20 by ibotnaru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC =	./pars_and_print/*.c \
		hashing_funcs.c hex_conversion.c md5_rounds.c md5steps.c \
		printing_hash.c sha256mainloop.c sha256steps.c main.c

LIBFT = ./libft/libft.a

# GCCW = gcc -g -fsanitize=address -Wall -Werror -Wextra
GCCW = gcc -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft re
	@$(GCCW) $(SRC) $(LIBFT) -o $(NAME)


clean:
	@make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all
