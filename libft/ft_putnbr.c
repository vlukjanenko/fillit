/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:59:49 by majosue           #+#    #+#             */
/*   Updated: 2019/09/13 13:29:10 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putabs(int n)
{
	unsigned int nbr;

	nbr = ABS(n);
	if (nbr != 0)
	{
		ft_putabs(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}

void		ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putabs(n);
	}
	else
		ft_putabs(n);
}
