/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 08:40:22 by majosue           #+#    #+#             */
/*   Updated: 2019/11/05 18:07:54 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	tsize(int *input2)
{
	int i;
	int v;
	int vx;
	int vy;

	i = 0;
	vx = 0;
	vy = 0;
	while (i < 4)
	{
		if (input2[i] % 4 > vx)
			vx = input2[i] % 4;
		if (input2[i] / 4 > vy)
			vy = input2[i] / 4;
		i++;
	}
	v = vy * 4 + vx;
	return (v);
}

int	add_n_t_to_sub(int v, int n, int size, int ***subsets)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (!((*subsets)[v] = (int*)malloc(sizeof(int) * 5)))
			return (0);
		(*subsets)[v][0] = n;
		i++;
		v++;
	}
	return (1);
}

int	add_to_subsets(int v, int *input2, int field, int ***subsets)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 1;
	while (j < (field - tsize(input2) / 4))
	{
		while (i < (field - tsize(input2) % 4))
		{
			while (k < 5)
			{
				(*subsets)[v][k] = (input2[k - 1] / 4 + j) *\
field + (input2[k - 1] % 4 + i);
				k++;
			}
			v++;
			i++;
			k = 1;
		}
		j++;
		i = 0;
	}
	return (0);
}

int	vars(int **input2, int field, int n, int ***subsets)
{
	int v;
	int ts;
	int j;

	v = 0;
	j = 0;
	while (j < n)
	{
		ts = tsize(input2[j]);
		if (subsets)
		{
			if (!(add_n_t_to_sub(v, j, (field - ts % 4) *\
(field - ts / 4), subsets)))
				return (0);
			add_to_subsets(v, input2[j], field, subsets);
		}
		v = v + (field - ts % 4) * (field - ts / 4);
		j++;
	}
	return (v);
}
