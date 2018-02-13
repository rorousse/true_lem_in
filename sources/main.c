/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:58:40 by rorousse          #+#    #+#             */
/*   Updated: 2018/02/13 19:46:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lem_in.h"

int main(void)
{
	t_problem test;

	test = get_setup(0);
	set_weight(test.lst);
	if (test.ret && test.nb_ants > 0 && check_valid_path(test.lst))
	{
		create_ants(&test);
		ft_resolve(test);
	}
	else
		ft_putendl("ERROR");
	free_pieces(test.lst);
	if (test.ants)
		free(test.ants);
	return (0);
}
