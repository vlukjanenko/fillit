/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 08:40:18 by majosue           #+#    #+#             */
/*   Updated: 2019/11/07 17:28:06 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int **g_answer = 0;
int g_depth = 0;

void	cleanup(int ***arr, int n)
{
	int i;

	i = 0;
	while (i < n)
		free((*arr)[i++]);
	free(*arr);
	*arr = 0;
	free(g_answer);
	g_answer = 0;
}

int		fillit(int **subsets, int size, int n)
{
	int rsize;
	int **rsubsets;
	int i;

	i = 0;
	while (i < size && subsets[0][0] == subsets[i][0])
	{
		g_answer[g_depth] = subsets[i];
		if (g_depth == (n - 1))
			return (1);
		if ((rsize = newsubset(subsets, i, size)))
		{
			g_depth++;
			if (!(rsubsets = (int**)malloc(sizeof(int*) * rsize)))
				return (0);
			frs(&subsets, &rsubsets, i, size);
			fillit(rsubsets, rsize, n);
			free(rsubsets);
			if (g_depth == (n - 1))
				return (1);
			g_depth--;
		}
		i++;
	}
	return (0);
}

int		init(int field, int n, int ***input2, int ***subsets)
{
	if (!g_answer)
		if (!(g_answer = (int**)malloc(sizeof(int*) * n)))
			return (0);
	if (*subsets)
		free(*subsets);
	if (!(*subsets = (int**)malloc(sizeof(int*) * vars(*input2, field, n, 0))))
		return (0);
	return (1);
}

int		doit(int n, int ***input2)
{
	int **subsets;
	int field;
	int j;

	subsets = 0;
	field = ft_sqrt
(n * 4);
	if (!(init(field, n, input2, &subsets)))
		return (0);
	j = vars((*input2), field, n, &subsets);
	while (!(fillit(subsets, j, n)))
	{
		cleanup(&subsets, j);
		if (!(init(++field, n, input2, &subsets)))
			return (0);
		j = vars((*input2), field, n, &subsets);
	}
	if (!(solveprint(field, g_answer, n)))
		return (0);
	cleanup(input2, n);
	cleanup(&subsets, j);
	return (1);
}

int		main(int argc, char **argv)
{
	int	fd;
	int n;
	int **input2;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit fillit_sample_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("usage: ./fillit fillit_sample_file");
		return (0);
	}
	n = getinput2(fd, &input2);
	if (n == 0)
	{
		close(fd);
		ft_putendl("error");
		return (0);
	}
	if (!(doit(n, &input2)))
		ft_putendl("error");
	close(fd);
	return (0);
}
