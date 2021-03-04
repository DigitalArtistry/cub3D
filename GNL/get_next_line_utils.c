/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:51:24 by lucisanc          #+#    #+#             */
/*   Updated: 2019/11/26 15:44:01 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_readbuff(int fd, char *c, t_struct *p_buff)
{
	int		r;

	if (p_buff->curr == p_buff->max)
	{
		if ((r = read(fd, p_buff->buffer, BUFFER_SIZE)) <= 0)
			return (r);
		p_buff->max = r;
		p_buff->curr = 0;
	}
	*c = (p_buff->buffer)[p_buff->curr];
	(p_buff->curr)++;
	return (1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_addchar(char c, char **line)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(*line);
	if (!(str = malloc(sizeof(char) * (len + 2))))
	{
		free(*line);
		return (-1);
	}
	while (i < len)
	{
		str[i] = (*line)[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = 0;
	free(*line);
	*line = str;
	return (0);
}
