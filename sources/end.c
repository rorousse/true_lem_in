/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:27:27 by rorousse          #+#    #+#             */
/*   Updated: 2017/09/27 19:28:35 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

static void	free_links(t_link *lst)
{
	t_link *tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	free_pieces(t_piece *lst)
{
	t_piece *tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free_links(lst->links);
		free(lst->id);
		free(lst);
		lst = tmp;
	}
}
