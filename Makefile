#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 16:04:38 by majosue           #+#    #+#              #
#    Updated: 2019/11/11 14:45:44 by majosue          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
HEADER = fillit.h
COMPILERC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES  =  fillit.c ft_sqrt.c getinput.c getinput2.c solveprint.c vars.c\
newsubset.c ft_putendl.c ft_putchar.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(COMPILERC) -o $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(COMPILERC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
