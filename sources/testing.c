/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:48:45 by rorousse          #+#    #+#             */
/*   Updated: 2016/11/21 16:48:47 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../libft/libft.h"
#include <stdio.h>

void	aff_lst(t_piece *lst)
{
	t_link *tmp;

	while (lst)
	{
		tmp = lst->links;
		ft_putstr("La piece ");
		ft_putstr(lst->id);
		ft_putstr(" a un poids de ");
		ft_putnbr(lst->weight);
		ft_putstr(" et a ");
		ft_putnbr(lst->full);
		ft_putendl(" fourmis");
		ft_putendl("Liste des links :");
		while (tmp)
		{
			ft_putstr("On a pour link ");
			if (tmp->room != NULL)
				ft_putendl((tmp->room)->id);
			else
				ft_putendl("NULL");
			tmp = tmp->next;
		}
		ft_putendl("fin de la liste des links");
		lst = lst->next;
	}
}