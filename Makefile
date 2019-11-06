#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 16:04:38 by majosue           #+#    #+#              #
#    Updated: 2019/11/06 17:44:48 by majosue          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
HEADER = fillit.h
HEADERS = ./libft/includes
COMPILERC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES  =  fillit.c ft_sqrt.c getinput.c getinput2.c solveprint.c vars.c\
newsubset.c
OBJECTS = $(SOURCES:.c=.o)
LIB = libft/libft.a


all: $(NAME)

$(NAME): $(OBJECTS) $(LIB) 
	$(COMPILERC) $(FLAGS) -L libft/ -I $(HEADERS) -lft $(OBJECTS) -o $(NAME)

$(LIB):
	make -C libft/

%.o: %.c $(HEADER)
	$(COMPILERC) $(FLAGS) -o $@ -c $< 

clean:
	@rm -f $(OBJECTS)
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ./libft fclean

re: fclean all
