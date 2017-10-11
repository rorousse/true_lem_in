/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:24:39 by rorousse          #+#    #+#             */
/*   Updated: 2016/11/24 16:25:12 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../libft/libft.h"

static void	move_ant(t_problem pb, int i, t_piece *end)
{
	t_link *tmp;
	t_piece *choice;

	choice = NULL;
	tmp = pb.ants[i].room->links;
	while (tmp)
	{
		if (tmp->room == end || (((tmp->room)->full == 0 && (choice == NULL || choice->weight > (tmp->room)->weight))))
			choice = tmp->room;
		tmp = tmp->next;
	}
	if (choice != NULL)
	{
		(pb.ants[i].room->full)--;
		pb.ants[i].room = choice;
		choice->full++;
		ft_putstr("L");
		ft_putnbr(i + 1);
		ft_putstr("-");
		ft_putstr(choice->id);
		ft_putchar(' ');
	}
}

void	ft_resolve(t_problem pb)
{
	t_piece *end;
	int		i;

	ft_putchar('\n');
	end = pb.lst;
	while (end->delim != END)
		end = end->next;
	while (end->full != pb.nb_ants)
	{
		i = 0;
		while (i < pb.nb_ants)
		{
			if (pb.ants[i].room != end)
			{
				move_ant(pb , i, end);
			}
			i++;
		}
		ft_putchar('\n');
	}
}
