/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:52:40 by majosue           #+#    #+#             */
/*   Updated: 2019/09/16 16:21:41 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t lend;
	size_t i;

	len = (size < ft_strlen(dst) ? size : ft_strlen(dst)) + ft_strlen(src);
	lend = ft_strlen(dst);
	if (!dst || !src)
		return (0);
	if (lend >= size)
		return (len);
	i = 0;
	while (i < (size - lend - 1) && src[i] != '\0')
	{
		*(dst + lend + i) = src[i];
		i++;
	}
	*(dst + lend + i) = '\0';
	return (len);
}
