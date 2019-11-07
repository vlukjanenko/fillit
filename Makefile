#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 16:04:38 by majosue           #+#    #+#              #
#    Updated: 2019/11/07 18:16:00 by majosue          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
HEADER = fillit.h
HEADERS = libft/includes
COMPILERC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES  =  fillit.c ft_sqrt.c getinput.c getinput2.c solveprint.c vars.c\
newsubset.c
OBJECTS = $(SOURCES:.c=.o)
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	$(COMPILERC) -o $(NAME) $(OBJECTS) -I $(HEADERS) -L libft/ -lft

%.o: %.c $(HEADER)
	$(COMPILERC) $(FLAGS) -I $(HEADERS) -o $@ -c $<

$(LIB):
	make -C libft/

clean:
	@rm -f $(OBJECTS)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
