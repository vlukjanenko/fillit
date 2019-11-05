/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:18:22 by majosue           #+#    #+#             */
/*   Updated: 2019/11/05 18:06:40 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	checkblock(char array[4][5])
{
	int i;
	int j;
	int m;
	int k;

	m = 0;
	i = 0;
	j = 0;
	k = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			(array[j][i] == '#') ? k++ : k;
			(i < 3 && array[j][i] == '#' && array[j][i + 1] == '#') ? m++ : m;
			(j < 3 && array[j][i] == '#' && array[j + 1][i] == '#') ? m++ : m;
			(i > 0 && array[j][i] == '#' && array[j][i - 1] == '#') ? m++ : m;
			(j > 0 && array[j][i] == '#' && array[j - 1][i] == '#') ? m++ : m;
			i++;
		}
		i = 0;
		j++;
	}
	m = (m >= 6 && k == 4) ? 1 : 0;
	return (m);
}

int	validarray(char (*array)[26][4][5], int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (!checkblock((*array)[i]))
			return (0);
		i++;
	}
	return (i);
}

int	valid(char *line)
{
	int i;

	i = 0;
	if (line[4] != '\n')
		return (0);
	while (i < 4)
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int	getinput(int fd, char (*input)[26][4][5])
{
	int		i;
	int		k;
	char	tmp;

	k = 0;
	i = 0;
	while (read(fd, (*input)[i][k], 5) > 0 && i < 26)
	{
		if (!valid((*input)[i][k]))
			return (0);
		(*input)[i][k][4] = 0;
		if (k == 3)
		{
			tmp = 0;
			read(fd, &tmp, 1);
			if (tmp != '\n' && tmp != 0)
				return (0);
			i++;
			if (tmp == 0)
				return (validarray(input, i));
		}
		(k == 3) ? (k = 0) : (k++);
	}
	return (0);
}
