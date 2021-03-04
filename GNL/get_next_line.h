/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:43:19 by lucisanc          #+#    #+#             */
/*   Updated: 2019/11/26 15:10:19 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/uio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 5

typedef struct	s_struct
{
	char		buffer[BUFFER_SIZE];
	int			max;
	int			curr;
}				t_struct;

int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
int				ft_addchar(char c, char **line);
int				ft_readbuff(int fd, char *c, t_struct *p_buff);

#endif
