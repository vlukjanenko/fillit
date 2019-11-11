/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:05:02 by majosue           #+#    #+#             */
/*   Updated: 2019/11/11 14:43:38 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_sqrt(int nb);
int		getinput(int fd, char (*input)[26][4][5]);
int		getinput2(int fd, int ***input2);
int		solveprint(int size, int **pos, int n);
int		vars(int **input2, int field, int n, int ***subsets);
int		newsubset(int **subsets, int k, int j);
void	frs(int ***subsets, int ***rsubsets, int k, int j);
void	ft_putchar(char c);
void	ft_putendl(char const *s);

#endif
