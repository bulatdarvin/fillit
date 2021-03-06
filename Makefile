# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssilvana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 13:14:58 by ssilvana          #+#    #+#              #
#    Updated: 2019/09/26 13:36:24 by ssilvana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c map.c solve.c math_and_init.c check.c

FUNCTION = main.o map.o solve.o math_and_init.o check.o

INCLUDE = header.h

all: $(NAME)

$(NAME): $(FUNCTION)
	@make -C libft all
	@gcc -o $(NAME) $(FUNCTION) libft/libft.a 

$(FUNCTION): %.o: %.c

clean:
	@/bin/rm -f $(FUNCTION)
	@/bin/rm -f *.h.gch
	@/bin/rm -f .*.swp
	@make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all
