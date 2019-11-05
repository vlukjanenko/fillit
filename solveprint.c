/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:08:54 by majosue           #+#    #+#             */
/*   Updated: 2019/10/29 15:23:04 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solveinit(char **arr, int size)
{
	int i;

	i = 0;
	while (i < size * size)
	{
		(*arr)[i] = '.';
		i++;
	}
}

void	solvefill(char **arr, int **pos, int n)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (j < n)
	{
		while (i < 5)
		{
			(*arr)[pos[j][i]] = pos[j][0] + 'A';
			i++;
		}
		i = 1;
		j++;
	}
}

int		solveprint(int size, int **pos, int n)
{
	int		i;
	char	*arr;

	if (!(arr = (char*)malloc(sizeof(char) * (size * size + 1))))
		return (0);
	arr[size * size] = 0;
	solveinit(&arr, size);
	solvefill(&arr, pos, n);
	i = 0;
	while (i < size * size)
	{
		if (i / size && !(i % size))
			ft_putchar('\n');
		ft_putchar(arr[i]);
		i++;
	}
	ft_putchar('\n');
	free(arr);
	return (1);
}
