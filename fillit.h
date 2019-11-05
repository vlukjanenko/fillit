/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:05:02 by majosue           #+#    #+#             */
/*   Updated: 2019/10/30 11:45:55 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/includes/libft.h"
# include <fcntl.h>

int		ft_sqrt(int nb);
int		getinput(int fd, char (*input)[26][4][5]);
int		getinput2(int fd, int ***input2);
int		solveprint(int size, int **pos, int n);
int		vars(int **input2, int field, int n, int ***subsets);
int		newsubset(int **subsets, int k, int j);
void	frs(int ***subsets, int ***rsubsets, int k, int j);

#endif
