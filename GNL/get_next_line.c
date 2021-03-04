/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:41:17 by lucisanc          #+#    #+#             */
/*   Updated: 2019/11/26 15:43:47 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_struct		buff;
	int					val;
	char				c;

	val = 0;
	c = 0;
	if (fd < 0 || !line || !(*line = (char *)malloc(sizeof(char))))
		return (-1);
	**line = 0;
	val = ft_readbuff(fd, &c, &buff);
	while (val == 1 && c != '\n')
	{
		if (ft_addchar(c, line))
			return (-1);
		val = ft_readbuff(fd, &c, &buff);
	}
	return (val);
}
