/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:58:40 by rorousse          #+#    #+#             */
/*   Updated: 2017/09/27 19:39:14 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lem_in.h"

int main(void)
{
	t_problem test;

	test = get_setup(0);
	if (test.ret && test.nb_ants > 0)
	{
		create_ants(&test);
		set_weight(test.lst);
		if (!(check_valid_path(test.lst)))
			ft_putendl("invalid path");
		else
			ft_resolve(test);
	}
	else
		ft_putendl("ERROR");
	free_pieces(test.lst);
	if (test.ants)
		free(test.ants);
	sleep(3);
	return (0);
}
