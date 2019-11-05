/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinput2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:32:40 by majosue           #+#    #+#             */
/*   Updated: 2019/10/29 15:21:00 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean(int ***input2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free((*input2)[i]);
		i++;
	}
	free(*input2);
}

void	fillcor(char (*input)[4][5], int **input2)
{
	int j;
	int i;
	int l;

	i = 0;
	j = 0;
	l = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			if ((*input)[j][i] == '#')
			{
				(*input2)[l] = i + j * 4;
				l++;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	corpos(int **input2)
{
	int i;
	int xc;
	int yc;

	xc = 4;
	yc = 4;
	i = 0;
	while (i < 4)
	{
		if ((*input2)[i] % 4 < xc)
			xc = (*input2)[i] % 4;
		if ((*input2)[i] / 4 < yc)
			yc = (*input2)[i] / 4;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*input2)[i] = ((*input2)[i] / 4 - yc) * 4 + ((*input2)[i] % 4 - xc);
		i++;
	}
}

int		getinput2(int fd, int ***input2)
{
	int		k;
	int		n;
	char	input[26][4][5];

	if (!(n = getinput(fd, &input)))
		return (0);
	if (!(*input2 = (int**)malloc(sizeof(int*) * n)))
		return (0);
	k = 0;
	while (k < n)
	{
		if (!((*input2)[k] = (int*)malloc(sizeof(int) * 4)))
		{
			clean(input2, k);
			return (0);
		}
		fillcor(&input[k], &(*input2)[k]);
		corpos(&(*input2)[k]);
		k++;
	}
	return (k);
}
