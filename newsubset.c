/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsubset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:36:26 by majosue           #+#    #+#             */
/*   Updated: 2019/11/07 21:34:55 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compare(int n, int m, int **subsets)
{
	int b;

	b = 1;
	if (subsets[n][0] == subsets[m][0])
		return (1);
	while (b < 5)
	{
		if (subsets[n][b] == subsets[m][1] ||\
				subsets[n][b] == subsets[m][2] ||\
				subsets[n][b] == subsets[m][3] ||\
				subsets[n][b] == subsets[m][4])
			return (1);
		b++;
	}
	return (0);
}

int		newsubset(int **subsets, int k, int j)
{
	int i;
	int n;

	n = 0;
	i = k;
	while (i < j)
	{
		if (compare(k, i, subsets) == 0)
		{
			n++;
		}
		i++;
	}
	return (n);
}

void	frs(int ***subsets, int ***rsubsets, int k, int j)
{
	int i;
	int n;

	n = 0;
	i = k;
	while (i < j)
	{
		if (compare(k, i, *subsets) == 0)
		{
			(*rsubsets)[n] = (*subsets)[i];
			n++;
		}
		i++;
	}
}
