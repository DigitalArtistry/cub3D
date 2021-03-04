/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:25:03 by lucisanc          #+#    #+#             */
/*   Updated: 2021/02/27 10:09:15 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parse		parsee;
	t_display	displayy;

	initparse(&displayy);
	if (argc == 1)
		return
		(showerror(&displayy, "Add map file as second argument"));
	if (argc > 3)
		return
		(showerror(&displayy, "More than two argument have been provided."));
	if (argc == 3 && cmp(argv[2], "--save", 6))
		return (showerror(&displayy, "Invalid second argument"));
	parse(argc, argv[1], &parsee, &displayy);
	display(&parsee, &displayy);
	return (EXIT_SUCCESS);
}
