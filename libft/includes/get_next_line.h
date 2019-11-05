/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:12:08 by majosue           #+#    #+#             */
/*   Updated: 2019/09/30 16:19:38 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE  32
# include "libft.h"

typedef struct	s_bufer
{
	char			*bufer;
	int				fd;
	struct s_bufer	*next;
	struct s_bufer	*prev;
}				t_bufer;

int				get_next_line(const int fd, char **line);

#endif
