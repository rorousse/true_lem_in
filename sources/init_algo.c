/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:34:34 by rorousse          #+#    #+#             */
/*   Updated: 2018/02/13 19:37:09 by rorousse         ###   ########.fr       */
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
	while (tmp)
	{
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
	if (lst != NULL)
	{
		init_set_weight(&lst);
		lst->weight = 0;
		set_weight_rec(lst);
	}
}
