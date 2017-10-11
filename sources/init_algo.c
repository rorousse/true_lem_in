/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:34:34 by rorousse          #+#    #+#             */
/*   Updated: 2016/11/21 15:34:36 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../libft/libft.h"

static void	init_set_weight(t_piece **lst)
{
		while ((*lst)->delim != END)
			*lst = (*lst)->next;
}

static void	set_weight_rec(t_piece *lst)
{
	t_link *tmp;

	tmp = lst->links;
	/*
	ft_putstr("On passe par ");
	ft_putendl(lst->id);
	*/
	while (tmp)
	{
		/*
		ft_putstr("On regarde le link ");
		ft_putendl((tmp->room)->id);
		*/
		if ((tmp->room)->weight == -1)
		{
			(tmp->room)->weight = (lst->weight) + 1;
		}
		tmp = tmp->next;
	}
	lst->weight_set = 1;
	tmp = lst->links;
	while (tmp)
	{
		if ((tmp->room)->weight_set == 0)
			set_weight_rec(tmp->room);
		tmp = tmp->next;
	}
}

void	set_weight(t_piece *lst)
{
	init_set_weight(&lst);
	lst->weight = 0;
	set_weight_rec(lst);
}