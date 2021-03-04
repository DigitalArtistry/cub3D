/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:50:21 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/01 15:42:54 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				ft_strlenght(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				arrondi(int number, int boleen)
{
	int index;

	index = 0;
	while (number > index)
		index++;
	if (boleen == 1)
		return (index);
	return (index - 1);
}

unsigned int	colortoint(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int	color;

	color = r << 16 | g << 8 | b;
	return (color);
}

char	*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}